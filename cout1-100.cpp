#include<iostream>
namespace one {
	struct X {
	public:
		static unsigned int value;
		X() {
			++value;
			std::cout << value << std::endl;
		}
	};
	unsigned int X::value = 0;
	void test() {
		X arr[100];
	}
}

namespace two {
	template<int N>
	struct X :private X<N - 1> {
		X() {
			std::cout << N << std::endl;
		}
	};
	template<>
	struct X<0> {

	};
	void test() {
		X<100> x;
	}
}