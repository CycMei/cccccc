#include <iostream>
#include <type_traits>
#include <typeinfo>

void MyConditional() {
	//和三目运算符相似，第一个模板参数为true,类型为第二个模板参数，否则类型为第二个模板参数
	typedef std::conditional<true, int, double>::type Type1;
	typedef std::conditional<false, int, double>::type Type2;
	typedef std::conditional<sizeof(int) >= sizeof(double), int, double>::type Type3;
	std::cout << typeid(Type1).name() << '\n';
	std::cout << typeid(Type2).name() << '\n';
	std::cout << typeid(Type3).name() << '\n';
}
void common_type() {
	struct Base {};
	struct Derived : Base {};
	std::cout << sizeof(Derived) << std::endl;						//1
	std::cout << sizeof(Base) << std::endl;							//1
	typedef std::common_type<char, short, int>::type A;           // int
	typedef std::common_type<float, double>::type B;             // double
	typedef std::common_type<Derived, Base>::type C;             // Base
	typedef std::common_type<Derived*, Base*>::type D;           // Base*
	typedef std::common_type<const int, volatile int>::type E;   // int
	std::cout << std::boolalpha;
	std::cout << "typedefs of int:" << std::endl;
	std::cout << "A: " << std::is_same<int, A>::value << std::endl;
	std::cout << "B: " << std::is_same<int, B>::value << std::endl;
	std::cout << "C: " << std::is_same<int, C>::value << std::endl;
	std::cout << "D: " << std::is_same<int, D>::value << std::endl;
	std::cout << "E: " << std::is_same<int, E>::value << std::endl;
}