#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<initializer_list>
#include<boost\bimap.hpp>
template<typename T>class Blob {
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	Blob(std::initializer_list<T> il);
	size_type size() const {
		return data->size();
	}
	bool empty() const {
		data->empty();
	}
	void push_back(const T &t) {
		data->push_back(t);
	}
	void push_back(T &&t) {
		data->push_back(std::move(t));
	}
	void pop_back();
	T &back();
	T &operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};
template<class T = int> class Numbes {
private:
	T val;
public:
	Numbes(T v = 0) :val(v) {};
};
Numbes<long double> lots_of_precision;
Numbes<> average;

class DebugDelete {
public:
	DebugDelete(std::ostream &s = std::cout) :os(s) {}
	template<typename T> void operator()(T *p) const {
		delete p;
	}
private:
	std::ostream &os;
};
void test() {
	int *p = new int(0);
	DebugDelete()(p);
	std::unique_ptr<int, DebugDelete> pps(new int(), DebugDelete());
}

template<typename T> class copyB {
	template<typename It> copyB(It b, It e);
};
template<typename T> template<typename It> copyB<T>::copyB(It b, It e) {
}
extern template class copyB<std::string>;
unsigned int myINT;



template<typename T> class Stack{};
void fc(Stack<char>){}
class Exercise {
	Stack<double> &rsd;
	Stack<int> si;
};
void copyMain() {
	//Stack<char> *sc;
	int iObj = sizeof(Stack<std::string>);
}
namespace stdds {
	//std::vector<int&> vcs;
	template<typename T> void g(T&& val){}
	template<typename T> void gg(T val){}
	template<typename T> void ggg(const T &val){}
	template<typename T> void gc(T &&val){
		std::vector<T> v;
	}
	
	template<typename T> typename std::remove_reference<T>::type &&move(T &&t) {
		return static_cast<typename std::remove_reference<T>::type&&>(t);
	}
	int i = 0;
	const int ci = i;
	void test() {
		g(i);
		g(ci);
		g(ci*i);
		g(i = ci);

		gg(i);
		gg(ci);
		gg(ci*i);
		gg(i = ci);

		ggg(i);
		ggg(ci);
		ggg(ci*i);
		ggg(i = ci);
		gc(42);
	//	gc(i);
	}
};
namespace trans {
	template<typename T1, typename T2> void flip1( T1 &&t1, T2 &&t2) {
	}
	template<typename T1, typename T2> void fss(const T1 &&t1, const T2 &&t2) {
	}
	void test() {
		int i = 0;
		int j = i;
		const int &c = i;
		flip1(i, j);
		//fss(i, j);
	}
	
}
namespace tracsws {
	template<typename T> void f(T t) {
		std::cout << 1 << std::endl;
	}
	template<typename T> void f(const T *t) {
		std::cout << 2 << std::endl;
	}
	template<typename T> void g(T t) {
		std::cout << 3 << std::endl;
	}
	template<typename T> void g(T *t) {
		std::cout << 4 << std::endl;
	}
	template<typename...Args> void g(Args...args) {
		std::cout << sizeof...(Args);
		std::cout << sizeof...(args);
	}
	template<typename T> std::ostream &print(std::ostream &os, const T &t) {
		return os << t;
	}
	template<typename T, typename...Args> std::ostream &print(std::ostream &os, const T &t, const Args... rest) {
		os << t << " ,";
		return print(os, rest...);
	}
	template<class... Args> void emplace_back(Args&&...) {
	}
	template<typename T> int compare(const T&, const T&) {};
	template<> int compare(const char *const &p1,const char *const &p2){}

};
void main() {
	using namespace tracsws;
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42);
	g(p);
	g(ci);
	g(p2);
	f(42);
	f(p);
	f(ci);
	f(p2);
}