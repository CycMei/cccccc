#include<string>
#include<iostream>
#include<vector>
namespace MyConst {
	void test() {
		char greeting[6] = "Hello";
		char *p = greeting;
		std::cout << p[2] << std::endl;
		std::cout << *p << std::endl;
		const char *p1 = greeting;
		char *const p2 = greeting;
		const char *const p3 = greeting;
	}
	void test1() {
		std::vector<int> vec;
		const std::vector<int>::iterator iter = vec.begin();
		//++iter;//const 是声明迭代器为常量，就像 T *const
		std::vector<int>::const_iterator cIter = vec.begin();
		++cIter;
	}
	class Rational {
	};
	const Rational operator*(const Rational &lhs, const Rational &rhs) {
		 Rational a;
		 return a;
	}
	void test2() {
		Rational a, b, c;
		//(a*b) = c;
	}
	class TextBlock {
	private:
		std::string text;
	public:
		TextBlock(const std::string &str):text(str){}
		const char &operator[](std::size_t position) const {
			std::cout << "1.........." << std::endl;
			return text[position];
		}
		char &operator[](std::size_t position) {
			std::cout << "2.........." << std::endl;
			return text[position];
		}
	};
	void print(const TextBlock &ctb) {
		std::cout << ctb[0] << std::endl;
	}
	void test3() {
		TextBlock tb(std::string("Hello"));//如果调用常量函数，需要进行转换，编译器不会这么做
		std::cout << tb[0] << std::endl;
		const TextBlock tb2(std::string("Hello"));
		std::cout << tb2[1] << std::endl;
		print(tb2);
	}
	class CTextBlock {
	private:
		char *pText;
	public:
		CTextBlock(char str[6]):pText(str){}
		char &operator[](std::size_t position) const {
			return pText[position];
		}
	};
	void test4() {
		char str[] = "Hello";
		const CTextBlock cctb(str);
		char *pc = &cctb[0];
		std::cout << *pc << std::endl;
		*pc = 'J';
		std::cout << *pc << std::endl;
	}
	class CCTextBlock {
	public:
		const char &operator[](std::size_t position) const {
			return text[position];
		}
		char &operator[](std::size_t position) {
			return const_cast<char&>(static_cast<const CCTextBlock&>(*this)[position]);
			//解引用生成左值:*this
		}
		CCTextBlock(std::string str):text(str){}
	private:
		std::string text;
	};
	void test5() {
		CCTextBlock cct("Hello");
		cct[0];
	}

}