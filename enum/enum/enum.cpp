#include<vector>
#include<iostream>
enum class myec {
	input,
	output,
	append
};
enum struct myes {
	input,
	output,
	append
};
myes m1 = myes::input;
enum color {
	red,
	yello,
	greed
};
color eyes = red;
color node = color::yello;
enum {
	floatP = 5,
	doublep = 10,
	doubel_pp = 2
} enum1, enum2;
enum class intTypes {
	charType = 8,
	shortType = 16,
	intType=16,
	longType=32,
	long_longType=64
};
enum class coutInt {
	int1 = 1,
	int2
};
enum intValues :unsigned long long {
	charType = 32343443
};
void test() {
	std::vector<int> vint{ 1,3,2 };
	constexpr coutInt index = coutInt::int2;
}
enum class ins:int;
//enum ins;
//enum ins :long;
