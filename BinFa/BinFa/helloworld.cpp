#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<thread>
#include<vector>
#include<string>
#include<algorithm>
namespace hello {
	void hello() {
		std::cout << "hello world" << std::endl;
		system("pause");
	}
	void printme() {
		std::cout << "me me me me " << std::endl;
	}
	int mmain() {
		std::thread t(hello);
		t.detach();
		if (t.joinable())
			t.join();
		printme();
		return 0;
	}
}
namespace beginthread {
	void do_something() {
		std::cout << "hello" << std::endl;
	}
	void do_something_other() {
		std::cout << "world" << std::endl;
	}
	class background_task {
	public:
		void operator()() const {
			do_something();
			do_something_other();
		}
	};
	void test() {
		background_task f;
		std::thread my_thread(f);
		my_thread.join();
	}
	void test1() {
		std::thread t1(background_task());		//this is a function
		std::thread t2((background_task()));	//normal
		t2.join();
		std::thread t3{ background_task() };	//normal
		if(t3.joinable())
			t3.detach();
		std::cout << "me me" << std::endl;
	}
	void test3() {
		std::thread t([]()->void {
			do_something();
			do_something_other();
		});
		t.join();
	}
}
namespace threadmethod {
	void do_something(unsigned int i) {
		std::cout << i << std::endl;
	}
	struct func {
		int &i;
		func(int &i_):i(i_){}
		void operator()() {
			for (unsigned int j = 0; j != 100000; ++j) {
				do_something(i);
			}
		}
	};
	void oops() {
		int some_local_state = 0;
		func my_func(some_local_state);
		std::thread my_thread(my_func);
		if (my_thread.joinable())
			my_thread.join();
		std::cout << "me me " << std::endl;
	}
	void f() {
		int some_local_state = 0;
		func my_func(some_local_state);
		std::thread t(my_func);
		try {
			do_something(100);
		}
		catch (...) {
			t.join();
			throw;
		}
		t.join();
	}
}
namespace rall {
	class thread_guard {
	private:
		std::thread &t;		//thread的拷贝构造函数是删除的
	public:
		explicit thread_guard(std::thread &t_):t(t_){}
		~thread_guard() {
			if (t.joinable()) {
				t.join();
			}
		}
		thread_guard(const thread_guard&) = delete;
		thread_guard &operator=(const thread_guard&) = delete;
	};
	using threadmethod::func;
	void f() {
		int some_local_state = 0;
		func my_func(some_local_state);
		std::thread t(my_func);
		thread_guard g(t);
	}
}
namespace canshu {
	void f(int i, const std::string &s) {
		std::cout << i << s << std::endl;
	}
	void mthread() {
		std::thread t(f, 3, "ssss");
		t.detach();
	}
	void oops(int some_param) {
		char buffer[1024];
		sprintf(buffer, "%i", some_param);
		std::thread t(f, 3,std::string(buffer));
		t.detach();
	}
	void updata(int w, int &data) {
		data = w + data;
	}
	void oops_again() {
		int data=2;
		std::thread t(updata, 3,std::ref(data));
		t.join();
		std::cout << data << std::endl;
	}
}
namespace X {
	class X {
	public:
		void do_length_work(int i){
			beginthread::do_something();
		}
	};
	X my_x;
	void test() {
		std::thread t(&X::do_length_work, &my_x,3);
		t.join();
	}
}
namespace move {
	void some_function() {}
	void some_other_functiong() {}
	void test1() {
		std::thread t1(some_function);
		std::thread t2 = std::move(t1);
		t1 = std::thread(some_other_functiong);
		t1.join();
		std::thread t3;
		t3 = std::move(t2);
		t3.join();
		t1 = std::move(t3);
		if (t1.joinable())
			t1.join();
	}
	std::thread f() {
		return std::thread(some_function);
	}
	std::thread g() {
		std::thread t(some_other_functiong);
		return t;
	}
	void ff(std::thread t) {
		t.detach();
	}
	void gg() {
		ff(std::thread(some_function));
		std::thread t(some_function);
		ff(std::move(t));
	}
}
namespace move1 {
	class scoped_thread {
	private:
		std::thread t;
	public:
		explicit scoped_thread(std::thread t_):t(std::move(t_)){
			if (!t.joinable())
				throw std::logic_error("no thread");
		}
		~scoped_thread() {
			t.join();
		}
		scoped_thread(const scoped_thread&) = delete;
		scoped_thread &operator=(const scoped_thread&) = delete;
	};
	using threadmethod::func;
	void f() {
		int some_local_state;
		scoped_thread t(std::thread(func(some_local_state)));
	}
	void do_work(unsigned int id){}
	void ff() {
		std::vector<std::thread> threads;
		for (unsigned int i = 0; i != 20; ++i) {
			threads.push_back(std::thread(do_work, i));
		}
	}
}
namespace getid {
	void do_something(){}
	std::thread::id d;
	void getId() {
		std::thread ts(do_something);
		ts.join();
		if (std::this_thread::get_id() != d)
			std::cout << std::boolalpha << true;
	}
}