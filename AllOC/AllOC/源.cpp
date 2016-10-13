#include<new>
#include<memory>
#include<vld.h>
#include<iostream>
namespace ptr {
	void test() {
		int *ptr = new int();
		delete ptr;
		int **handle;
		handle = new int*(NULL);
		*handle = new int();
		delete *handle;
		delete handle;
		int *ppt = new(std::nothrow) int();
		delete ppt;
	}
	class Simple {
	public:
		Simple(){}
		int getInt(int a, int b) const {
			return 2;
		}
		virtual ~Simple(){}
	};
	void test2() {
		int myArray[5]{};
		int *myArrayPtr = new int[5];
		delete[]myArrayPtr;
		int a = 3;
		int *arr = new int[a];
		delete[]arr;
		Simple *sim = new Simple[4];
		delete[]sim;
		std::size_t arrSize = 4;
		Simple **s = new Simple*[arrSize];
		for (std::size_t i = 0; i != arrSize; ++i) {
			s[i] = new Simple();
		}
		for (std::size_t i = 0; i != arrSize; ++i) {
			delete s[i];
		}
		delete[]s;
		s = nullptr;
	}
	char **temp(std::size_t x, std::size_t y) {
		char **myArr = new char*[x];
		for (std::size_t i = 0; i != x; ++i) {
			myArr[i] = new char[y];
		}
		return myArr;
	}
	void test3() {
		char **te=temp(3, 2);
		for (std::size_t i = 0; i != 3; ++i) {
			delete[]te[i];
		}
		delete[]te;
	}
	void test4(int *theArr, std::size_t inSize) {
		for (std::size_t i = 0; i != inSize; ++i) {
			theArr[i] *= 2;
		}
	}
	void test5() {
		char *sca = (char*)7;
		int myArr[5]{};
		int *temp = myArr;
		std::size_t size = 4;
		int *heapArr = new int[size] {2, 2, 23, 3};
		test4(heapArr, size);
		delete[]heapArr;
		heapArr = nullptr;
	}
	void testt6() {
		int *myArr = new int[8];
		myArr[2] = 4;
		*(myArr + 2) = 33;
		std::cout << myArr[2] << std::endl;
		delete[]myArr;
	}
	using MatchFcn = bool(*)(int, int);
	bool inEqul(int in1, int in2) {
		return in1 == in2;
	}
	void findMathes(int values1[], int values2[], std::size_t numValues, MatchFcn inFunc) {
		for (std::size_t i = 0; i != numValues; ++i) {
			if (inFunc(values1[i], values2[i])) {
				std::cout << "here" << std::endl;
			}
		}
	}
	void test7() {
		int arr1[]{ 2,3,2,3,2,3 };
		int arr2[]{ 2,3,2,3,2,3 };
		int arrSize = sizeof(arr1) / sizeof(arr1[0]);
		findMathes(arr1, arr2, arrSize, inEqul);
	}
	void test8() {
		int(Simple::*ptrFun)(int, int) const = &Simple::getInt;
		Simple ss;
		(ss.*ptrFun)(1,2);
	}
}
namespace dongtai {
	void test() {
		std::unique_ptr<int> myuptr(new int());
		auto temp=std::make_unique<int>();
		std::unique_ptr<int[]> myArrptr(new int[10]{});
		auto temp2 = std::make_unique<int[]>(10);
	}
	int *malloc_int(int value) {
		int *p = (int*)malloc(sizeof(int));
		*p = value;
		return p;
	}
	void test2() {
		auto deleter = [](int *p) {free(p); };
		std::unique_ptr<int, decltype(deleter)> myInPtr(malloc_int(42), deleter);
	}
	void test3() {
		auto myAuto = std::make_shared<int>(3);
	}
	class Base{};
	class Derived:public Base{};
	void test5() {
		std::shared_ptr<Base> myBase(new Derived());
		std::shared_ptr<Derived> myDir = std::static_pointer_cast<Derived>(myBase);
		std::shared_ptr<int> myInt(new int(), free);
	}
}
void main() {
	dongtai::test5();
}