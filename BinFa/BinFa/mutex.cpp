#include<map>
#include<string>
#include<mutex>
#include<list>
#include<exception>
#include<stack>
#include<boost\thread\shared_mutex.hpp>
#include<boost\thread\shared_lock_guard.hpp>
namespace firstmutex {
	class some_data {
	private:
		int a;
		std::string b;
	public:
		void do_something(){}
	};
	class data_wrapper {
	private:
		some_data data;
		std::mutex m;
	public:
		template<typename Fun> void process_data(Fun fun) {
			std::lock_guard<std::mutex> ws(m);
			fun(data);
		}
	};
	some_data *unprotected;
	void malicious_functiong(some_data &protected_data) {
		unprotected = &protected_data;
	}
	data_wrapper x;
	void foo() {
		x.process_data(malicious_functiong);
		unprotected->do_something();
	}
}
namespace onemutex {
	std::list<int> some_list;
	std::mutex some_mutex;
	void add_to_list(int new_value) {
		std::lock_guard<std::mutex> guard(some_mutex);
		some_list.push_back(new_value);
	}
	bool list_contains(int value_to_find) {
		std::lock_guard<std::mutex> guard(some_mutex);
		return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
	}
	void mthread() {
		std::thread t1(add_to_list, 100);
		t1.detach();
		std::thread t2(list_contains, 10);
		t2.detach();
	}
}
namespace safe {
	struct empty_stack :std::exception {
		const char *what() const throw(){
			return "erro";
		}
	};
	template<typename T> class threadsafe_stack {
	private:
		std::stack<T> data;
		mutable std::mutex m;
	public:
		threadsafe_stack(){}
		threadsafe_stack(const threadsafe_stack &other) {
			std::lock_guard<std::mutex> lock(other.m);
			data = other.data;
		}
		threadsafe_stack &operator=(const threadsafe_stack&) = delete;
		void push(T &new_value) {
			std::lock_guard<std::mutex> lock(m);
			data.push(new_value);
		}
		std::shared_ptr<T> pop() {
			std::lock_guard<std::mutex> lock(m);
			if (data.empty())
				return{};
			const std::shared_ptr<T> res(std::make_shared<T>(data.top()));
			data.pop();
			return res;
		}
		void pop(T &value) {
			std::lock_guard<std::mutex> lock(m);
			if (data.empty())
				throw empty_stack();
			value = data.top();
			data.pop();
		}
		bool empty() const {
			std::lock_guard<std::mutex> lock(m);
			return data.empty;
		}
	};
}
namespace dielock {
	class some_big_object {

	};
	void swap(some_big_object &lhs, some_big_object &rhs){}
	class X;
	void sswar(X &lhs, X &rhs);
	class X {
	private:
		some_big_object some_detail;
		std::mutex m;
	public:
		X(const X&) = delete;
		X(const some_big_object &sd):some_detail(sd){}
		friend void sswar(X &lhs, X &rhs) {
			if (&lhs == &rhs)
				return;
			std::lock(lhs.m, rhs.m);
			std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
			std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
			swap(lhs.some_detail, rhs.some_detail);
		}
	};
	void test() {
		some_big_object b1;
		some_big_object b2;
		X x1(b1);
		X x2(b2);
		sswar(x1, x2);
	}
	void test1();
	void do_something() {
		std::thread t2(test1);
		t2.join();
	}
	void test1() {
		std::thread t1(do_something);
		t1.join();
	}
}
namespace hie {
	class hie {
	private:
		std::mutex internal_mutex;
		const unsigned long hie_value;
		unsigned long pre_hie_value;
		static thread_local unsigned long this_thread_hie_value;
		void check_for_hie_violation() {
			if (this_thread_hie_value <= hie_value)
				throw std::logic_error("mutex hie violated");
		}
		void update_hie_value() {
			pre_hie_value = this_thread_hie_value;
			this_thread_hie_value = hie_value;
		}
	public:
		explicit hie(unsigned long value):hie_value(value),pre_hie_value(0){}
		void lock() {
			check_for_hie_violation();
			internal_mutex.lock();
			update_hie_value();
		}
		void unlock() {
			this_thread_hie_value = pre_hie_value;
			internal_mutex.unlock();
		}
		bool try_lock() {
			check_for_hie_violation();
			if (!internal_mutex.try_lock())
				return false;
			update_hie_value();
			return true;
		}
	};
	thread_local unsigned long hie::this_thread_hie_value(ULONG_MAX);
	hie hight(10000);
	hie low(5000);
	int do_low_level_stuff(){
		return 0;
	}
	int low_level_func() {
		std::lock_guard<hie> lk(low);
		return do_low_level_stuff();
	}
	void high_level_stuff(int some_param){}
	void high_level_func() {
		std::lock_guard<hie> lk(hight);
		high_level_stuff(low_level_func());
	}
	void thread_a() {
		high_level_func();
	}
}
namespace uniquelock {
	void test() {
		std::mutex m;
		std::unique_lock<std::mutex> u(m, std::defer_lock);
		u.lock();
	}
	class some_big_object {

	};
	void swap(some_big_object &lhs, some_big_object &rhs) {}
	class X;
	void sswar(X &lhs, X &rhs);
	class X {
	private:
		some_big_object some_detail;
		std::mutex m;
	public:
		X(const X&) = delete;
		X(const some_big_object &sd) :some_detail(sd) {}
		friend void sswar(X &lhs, X &rhs) {
			if (&lhs == &rhs)
				return;
			std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock);
			std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock);
			std::lock(lock_a, lock_b);
			swap(lhs.some_detail, rhs.some_detail);
		}
	};
	void do_something(){}
	std::mutex some_mutex;
	std::unique_lock<std::mutex> get_lock() {
		std::unique_lock<std::mutex> lk(some_mutex);
		do_something();
		return lk;
	}
	void process_data() {
		std::unique_lock<std::mutex> lk(get_lock());
		do_something();
	}
	void get_and_process_data() {
		std::unique_lock<std::mutex> my_lock(some_mutex);
		my_lock.unlock();
		my_lock.lock();
	}
}
namespace Y {
	class y {
	private:
		int some_detail;
		mutable std::mutex m;
		int get_detail() const {
			std::lock_guard<std::mutex> lock_a(m);
			return some_detail;
		}
	public:
		y(int sd) :some_detail(sd) {};
		friend bool operator==(const y &lhs, const y &rhs) {
			if (&lhs == &rhs)
				return true;
			const int lhs_value = lhs.get_detail();
			const int rhs_value = rhs.get_detail();
			return lhs_value == rhs_value;
		}
	};
}
namespace flag {
	std::shared_ptr<int> resourec_ptr;
	std::once_flag resource_flag;
	void init_resource() {
		resourec_ptr.reset(new int);
	}
	void foo() {
		std::call_once(resource_flag, init_resource);
	}
	class my_class{};
	my_class &get_my_class_instance() {
		static my_class instance;
		return instance;
	}
	class dns_entry{};
	class dns_cache {
	private:
		std::map<std::string, dns_entry> entries;
		mutable boost::shared_mutex entry_mutex;
	public:
		dns_entry find_entry(const std::string &domain) const {
			boost::shared_lock_guard<boost::shared_mutex> lk(entry_mutex);
			const std::map<std::string, dns_entry>::const_iterator it = entries.find(domain);
			return (it == entries.end()) ? dns_entry() : it->second;
		}
		void update_or_add_entry(const std::string &domain, const dns_entry &dns_details) {
			std::lock_guard<boost::shared_mutex> lk(entry_mutex);
			entries[domain] = dns_details;
		}
	};
	std::recursive_mutex r;
	void trys() {
		std::lock_guard<std::recursive_mutex> lk(r);
		std::lock_guard<std::recursive_mutex> lk1(r);
	}
}
