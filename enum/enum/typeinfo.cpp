
#include<string>
#include<iostream>
#include<typeinfo>
void test1() {
	int arr[10]{};
	std::string ss;
	const int &a = 2;
	const std::string *res = &ss;
	std::cout << typeid(res).name() << std::endl;
	std::cout << typeid(a).name() << std::endl;
	std::cout << typeid(int).name() << std::endl;
	std::cout << typeid(42).name() << std::endl;
	std::cout << typeid(arr).name() << std::endl;
	std::cout << typeid(ss).name() << std::endl;
	std::cout << typeid(&arr).name() << std::endl;
	std::cout<<std::boolalpha << typeid(ss).before(typeid(arr)) << std::endl;
}
class Base {
	friend bool operator==(const Base &lhs, const Base &rhs);
public:
protected:
	virtual bool equal(const Base&) const;
};
class Derived :public Base {
protected:
	bool equal(const Base&) const;
};
bool operator==(const Base &lhs, const Base &rhs) {
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}
//bool Derived::equal(const Base &rhs) const {
//	auto r=dynamic_cast<const Derived&>(rhs);
//}
void test221() {
	Derived *bp = nullptr;
	Derived *result=dynamic_cast<Derived*>(bp);
	if (result == nullptr)
		std::cout << std::boolalpha << true << std::endl;
}
