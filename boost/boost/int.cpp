#include<boost\lexical_cast.hpp>
#include<boost\array.hpp>
#include<iostream>

void main() {
	using boost::lexical_cast;
	int a = lexical_cast<int>("123");
	double b = lexical_cast<double>("123.12");
	std::string res = lexical_cast<std::string>(1234);
	std::cout << a << std::endl << b << std::endl;
	int aaa = int(3);
	std::string ss("32222sd");
	std::size_t sz;
	auto resu=std::stoi(ss, &sz, 16);
}
