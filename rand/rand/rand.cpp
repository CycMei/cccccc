#include<iostream>
#include<random>
#include<vector>
#include<ctime>
#include<cmath>
//std::default_random_engine e;
//std::default_random_engine copyE(10);
//std::uniform_int_distribution<unsigned> uid(0, 9);
std::default_random_engine e(time(nullptr));
std::uniform_int_distribution<unsigned int> u(0, 9);
std::vector<unsigned> bad_randVec() {
	
	std::vector<unsigned int> ret;
	for (size_t i = 0; i != 100; ++i) {
		ret.push_back(u(e));
	}
	return ret;
}
void cmian() {
	std::default_random_engine e;
	std::uniform_real_distribution<double> u(0, 1);
	std::uniform_real_distribution<> uu(0, 10);
	u(e);
	u.min();
	u.max();
	u.reset();
}
void normal_engine() {
	std::default_random_engine e;
	std::normal_distribution<> n(4, 1.5);
	std::vector<unsigned int> vals(9);
	for (size_t i = 0; i != 200; ++i) {
		unsigned int v = lround(n(e));
		if (v < vals.size())
			++vals[v];
	}
}
void dcc() {
	std::bernoulli_distribution b;
	std::bernoulli_distribution b(.55);
}
void main() {
	std::vector<unsigned int> res=bad_randVec();
	std::vector<unsigned int> re = bad_randVec();
	if (res == re)
		std::cout << std::boolalpha << true;
	//copyE.seed(100);
	//for (std::size_t i = 0; i != 10; ++i)
	//	std::cout << uid(e) << std::endl;
	//std::cout << e.min() << std::endl;
	//std::cout << e.max() << std::endl;
	//std::default_random_engine::result_type sz = e();
	//std::cout << sz;
	//unsigned long long u = 2;
	//e.discard(u);
}