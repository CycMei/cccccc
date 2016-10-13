#define D_SCL_SECURE_NO_WARNINGS
#include"StrBlob.h"
#include<new>
#include<vld.h>
#include<memory>
#include<iostream>
#include<string>
#include<cstdlib>

namespace shared_ptr {
	void test() {
		int *p=nullptr;
		if (p == nullptr)
			std::cout << "nullptr" << std::endl;
		std::shared_ptr<int> ptr_int;
		std::shared_ptr<std::string> ptr_str;
		std::shared_ptr<double> ptr_dou;
		if (ptr_int == nullptr)
			std::cout << "default is nullptr" << std::endl;
		if(ptr_str==0)
			std::cout << "default is nullptr" << std::endl;
		if (ptr_dou == NULL)
			std::cout << "default is nullptr" << std::endl;
		if (ptr_str&&ptr_str->empty())
			*ptr_str = std::string("sss");
	}
	class MyClass{
	public:
		MyClass() = delete;
		MyClass(std::string str):cstr(str){}
		std::string cstr;
	};
	void test2() {
		std::shared_ptr<int> p_int = std::make_shared<int>(42);
		std::shared_ptr<std::string> p_str = std::make_shared<std::string>("cyc");
		std::shared_ptr<int> p_ints = std::make_shared<int>();
		std::shared_ptr<MyClass> p_MyClass = std::make_shared<MyClass>(std::string("cyc"));
		std::cout << p_str->size() << std::endl;
		std::cout << *p_int << std::endl;
		std::cout << p_MyClass->cstr << std::endl;
		std::shared_ptr<int> p = std::make_shared<int>(42);
		auto r = std::make_shared<int>(42);
		r = p;
	}
	std::shared_ptr<int> returnInt() {
		std::shared_ptr<int> ptr_int = std::make_shared<int>(42);
		return ptr_int;
	}
	void testStrBlob() {
		StrBlob myStrBlob{ "cyc","lym" };
		std::cout<<myStrBlob.size();
		StrBlob myStrBlob1 = myStrBlob;
	}
	void test2StrBlob() {
		StrBlob b1;
		{
			StrBlob b2{ "a","an","the" };
			b1 = b2;
			b2.push_back("about");
		}
		std::cout << b1.size();
		b1.pop_back();
	}
}
namespace news {
	void test() {
		int *p1 = new int(2);
		
		std::string *ps = new std::string(10, 'c');
		delete ps;
		std::vector<int> *pve = new std::vector<int>{ 1,2,34,4 };
		delete pve;
		int *pint = new int();
		delete pint;
		auto pauto = new auto(std::string("string"));
		delete pauto;
		const std::string *pcs = new const std::string;
		delete pcs;
		const int *pcint = new const int;
		
		std::cout << *pcint;
		std::cout << *p1;
		delete pcint;
		delete p1;
		int *p2 = new (std::nothrow) int();
		delete p2;
	}
	bool b() {
		int *p = new int();
		return p;
		}
	void test3() {
		std::shared_ptr<int> p2(new int(42));
		std::shared_ptr<std::string> pstr{ new std::string("ssss") };
		std::shared_ptr<double> pdoub(new double(2.3));
	}
	std::shared_ptr<int> clone(int p) {
		return std::shared_ptr<int>(new int(p));
	}
	std::shared_ptr<int> pp(new int(42));
	void process(std::shared_ptr<int> ptr) {
		std::cout << pp.use_count() << std::endl;
		std::cout << ptr.use_count() << std::endl;
		std::cout << *ptr << std::endl;
	}
	void testprocess() {
		std::shared_ptr<int> p(new int(42));
		process(p);
		int i = *p;
		std::cout << i << std::endl;
	}
	void test2proce() {
		int *x(new int(1024));
		process(std::shared_ptr<int>(x));
		int i = *x;
		std::cout << i << std::endl;
	}
	void test5() {
		std::shared_ptr<int> p(new int(42));
		std::shared_ptr<int> q(p);
		std::cout << p.use_count() << std::endl;
		if (!p.unique())
			p.reset(new int(22));
		std::cout << p.use_count() << std::endl;
		*p = 100;
		std::cout << *p << std::endl;
		//std::cout << *p << std::endl;
	}
	void test6() {
		process(std::shared_ptr<int>(pp));
	}
	void tdds() {
		auto sp = std::make_shared<int>();
		auto p = sp.get();
		//delete p;
	}
}
namespace unique {
	void test1() {
		std::unique_ptr<double> pd;
		if (pd == nullptr)
			std::cout << std::boolalpha << true << std::endl;
		std::unique_ptr<int> uint(new int(22));
		uint = nullptr;
		std::unique_ptr<std::string> p1(new std::string("sss"));
		std::unique_ptr<std::string> p2(p1.release());
		if (p1 == nullptr) {
			std::cout << std::boolalpha << true << std::endl;
		}
		std::unique_ptr<std::string> p3(new std::string("ssdff"));
		p2.reset(p3.release());
	}
	std::unique_ptr<int> clone(int p) {
		std::unique_ptr<int> ret(new int(p));
		return ret;
	}
	std::unique_ptr<int> clone() {
		return std::unique_ptr<int>(new int(2));
	}
	void test3() {
		int ix = 1024;
		int *pi = &ix;
		int *pi2 = new int(2040);
		typedef std::unique_ptr<int> intP;
		intP p2(pi2);
		intP p3(p2.get());
	}
}
namespace weaks {
	void test() {
		std::weak_ptr<int> pweint;
		std::shared_ptr<int> psint(new int(32));
		std::shared_ptr<int> psintcs(psint);
		pweint = psint;
		std::cout << pweint.use_count() << std::endl;
		if (std::shared_ptr<int>  np = pweint.lock()) {
			std::cout << "cskddd" << std::endl;
		}
		pweint.reset();
	}
}
namespace arrays {
	void test() {
		int asize = 3;
		int *pia = new int[asize];
		delete[]pia;
		typedef int arrT[42];
		int *pa = new arrT;
		delete[]pa;
		int *piia = new int[2];
		delete[]piia;
		int *pia2 = new int[3]();
		delete[]pia2;
		std::string *psa = new std::string[3];
		delete[]psa;
		std::string *psa2 = new std::string[2]();
		delete[]psa2;
		std::string *psa3 = new std::string[2]{ "ss","ss" };
		delete[]psa3;
		char *cp = new char[0];
		delete[]cp;
	}
	void stes() {
		std::unique_ptr<int[]> up(new int[3]());
		//up.release();
		std::cout<<up[0];
		std::shared_ptr<int> sp(new int[10](), [](int *p) {delete[]p; });
		int *ppas = new int[3];
		delete[]ppas;
	}

}
namespace allocator {
	void test() {
		std::allocator<std::string> alloc;
		auto p=alloc.allocate(3);
		alloc.construct(p,"cyc");
		std::cout << *(p) << std::endl;
		alloc.destroy(p);
		alloc.deallocate(p, 3);
	}
	void test1() {
		//std::vector<int> vi{ 1,2,3 };
		//std::allocator<int> alloc;
		//int *p=alloc.allocate(vi.size() * 2);
		//auto res=std::uninitialized_copy(vi.begin(), vi.end(), p);
		//int *ress=std::uninitialized_fill_n(res, vi.size(), 42);
	}
}
void *operator new(std::size_t t){
	if (void *mem = std::malloc(t)) {
		return mem;
	}
	else {
		throw std::bad_alloc();
	}
}
void operator delete(void *mem) noexcept {
	free(mem);
}
//void *operator new(std::size_t);
//void *operator new[](std::size_t);
//void operator delete[](void*) noexcept;
//void *operator new(std::size_t, std::nothrow_t&) noexcept;
//void *operator new[](std::size_t, std::nothrow_t&) noexcept;
//void operator delete(void*, std::nothrow_t&) noexcept;
//void operator delete[](void*, std::nothrow_t&) noexcept;
void *operator new(std::size_t s,int*){
	return std::malloc(s);
}
void testss() {
	int *pp = nullptr;
	int *rep=new (pp) int();
	::delete rep;
}
namespace mynew {
}

void main() {
	allocator::test1();
}