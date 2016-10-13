#include<list>
#include<mutex>
#include<queue>
#include<deque>
#include<memory>
#include<condition_variable>
#include<future>
#include<iostream>
#include<utility>
#include<chrono>
#include<functional>
namespace skeeo {
	bool flag;
	std::mutex m;
	void wait_for_flag() {
		std::unique_lock<std::mutex> lk(m);
		while (!flag) {
			lk.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			lk.lock();
		}
	}
}
namespace condition {
	std::mutex mut;
	std::queue<int> data_queue;
	std::condition_variable data_cond;
	void data_preparation_thread() {
		int data = 2;
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(data);
		data_cond.notify_one();
	}
	void data_processing_thread() {
		while (true) {
			std::unique_lock<std::mutex> lk(mut);
			data_cond.wait(lk, [] {
				return !data_queue.empty();
			});
			int data = data_queue.front();
			data_queue.pop();
			lk.unlock();
		}
	}
}
namespace nqueue {
	//template<typename T,typename Container=std::deque<T>> class nqueue {
	//public:
	//	explicit nqueue(const Container&);
	//	explicit nqueue(Container && = Container());
	//	template<typename Alloc> explicit nqueue(const Alloc&);
	//	template<typename Alloc> nqueue(const Container&£¬const Alloc&);
	//	template<typename Alloc> nqueue(Container&&, const Alloc);
	//	template<typename Alloc> nqueue(nqueue&&, const Alloc&);
	//	void swap(nqueue &q);
	//	bool empty() const;
	//	size_type size() const;
	//	T &front();
	//	const T &front() const;
	//	T &back();
	//	const T &back() const;
	//	void push(const T &x);
	//	void push(T &&x);
	//	void pop();
	//	template<typename... Args> void emplace(Args&&... args);
	//};
	template<typename T> class threadsafe_queue {
	private:
		mutable std::mutex mut;
		std::queue<T> data_queue;
		std::condition_variable data_cond;
	public:
		threadsafe_queue(){}
		threadsafe_queue(const threadsafe_queue &other) {
			std::lock_guard<std::mutex> lk(other.mut);
			data_queue = other.data_queue;
		}
		threadsafe_queue &operator=(const threadsafe_queue&) = delete;
		void push(T new_value) {
			std::lock_guard<std::mutex> lk(mut);
			data_queue.push(new_value);
			data_cond.notify_one();
		}
		bool try_pop(T &value) {
			std::lock_guard<std::mutex> lk(mut);
			if (data_queue.empty())
				return false;
			value = data_queue.front();
			data_queue.pop();
			return true;
		}
		std::shared_ptr<T> try_pop() {
			std::lock_guard<std::mutex> lk(mut);
			if (data_queue.empty())
				return std::shared_ptr<T>();
			std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
			data_queue.pop();
			return res;
		}
		void wait_and_pop(T &value) {
			std::unique_lock<std::mutex> lk(mut);
			data_cond.wait(lk, [this] {return !data_queue.empty(); });
			value = data_queue.front();
			data_queue.pop();
		}
		std::shared_ptr<T> wait_and_pop() {
			std::unique_lock<std::mutex> lk(mut);
			data_cond.wait(lk, [this] {return !data_queue.empty(); });
			std::shared_ptr<T> res = std::make_shared<T>(data_queue.front());
			data_queue.pop();
			return res;
		}
		bool empty() const {
			std::lock_guard<std::mutex> lk(mut);
			return data_queue.empty();
		}
	};
	threadsafe_queue<int> ss;
	void ps() {
		ss.push(3);
	}
	void pop() {
		ss.wait_and_pop();
	}
	void test() {
		std::thread t1(ps);
		std::thread t2(pop);
		t1.detach();
		t2.detach();
	}
}
namespace futrue {
	int find_the_answer_to_value(){
		return 0;
	}
	void do_other_stuff() {};
	void test() {
		std::future<int> the_answer = std::async(find_the_answer_to_value);
		do_other_stuff();
		the_answer.get();
	}
	struct X {
		void foo(int a,const std::string &str){}
		std::string bar(const std::string &str){
			return{};
		}
	};
	X x;
	std::future<void> f1 = std::async(&X::foo, &x, 42, "hello");
	std::future<std::string> f2 = std::async(&X::bar, x, "goodbye");
	struct Y {
		double operator()(double d){
			return 0.0;
		}
	};
	Y y;
	std::future<double> f3 = std::async(Y(), 3.141);
	std::future<double> f4 = std::async(std::ref(y), 2.718);
	X baz(X&){
		X x;
		return x;
	}
	std::future<X> f5=std::async(baz, std::ref(x));
	//class move_only {
	//public:
	//	move_only();
	//	move_only(move_only&&);
	//	move_only(const move_only&) = delete;
	//	move_only &operator=(move_only&&);
	//	move_only &operator=(const move_only&) = delete;
	//	void operator()();
	//};
	//auto f6=std::async(move_only());
	auto f7 = std::async(std::launch::deferred | std::launch::async, baz, std::ref(x));
}
namespace packaged {
	std::mutex m;
	std::deque<std::packaged_task<void()>> tasks;
	bool gui_shutdown() {
		return false;
	}
	void get_and_gui(){}
	void gui_thread() {
		while (!gui_shutdown()) {
			get_and_gui();
			std::packaged_task<void()> task;
			{
				std::lock_guard<std::mutex> lk(m);
				if (tasks.empty())
					continue;
				task = std::move(tasks.front());
				tasks.pop_front();
			}
			task();
		}
	}
	std::thread gui_bg_thread(gui_thread);
	template<typename Func> std::future<void> post_task_for_gui_thread(Func f) {
		std::packaged_task<void()> task(f);
		std::future<void> res = task.get_future();
		std::lock_guard<std::mutex> lk(m);
		tasks.push_back(std::move(task));
		return res;
	}
}
namespace mtime {
	void gettime() {
		auto times=std::chrono::system_clock::now();
		std::chrono::duration<short, std::ratio<60, 1>>;
	}
}
namespace listsort {
	template<typename T> std::list<T> mquick_sort(std::list<T> input) {
		if (input.empty())
			return input;
		std::list<T> result;
		result.splice(result.begin(), input, input.begin());
		const T &pivot = *result.begin();
		std::list<T>::iterator divide=std::partition(input.begin(), input.end(), [&](const T &t) {
			return t < pivot;
		});
		std::list<T> lower_part;
		lower_part.splice(lower_part.end(), input, input.begin(), divide);
		std::list<T> newlower = mquick_sort(std::move(lower_part));
		std::list<T> newhigher = mquick_sort(std::move(input));
		result.splice(result.end(), newhigher);
		result.splice(result.begin(), newlower);
		return result;
	}
	std::list<int> n{ 2,3,4,42,1,23,3 };
	void test() {
		mquick_sort(n);
		for (auto c : n)
			std::cout << c << "  ";
	}
}
