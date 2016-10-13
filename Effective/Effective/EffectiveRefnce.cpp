#include<string>
#include<vector>
#include<iostream>

namespace Refnce {
	class Person {
	private:
		std::string name;
		std::string address;
	public:
		Person(){}
		virtual ~Person() {

		}
	};
	class Student :public Person {
	private:
		std::string schoolName;
		std::string schoolAddress;
	public:
		Student(){}
		~Student() {

		}
	};
	bool validateStudent(Student s) {
		return false;
	}
	Student plato;
	bool platoIsOK = validateStudent(plato);

	class Window {
	public:
		std::string name() const;
		virtual void display() const;
	};
	class WindowWithScrollBars :public  Window {
	public:
		virtual void display() const;
	};


	class Rational {
	public:
		//Rational(int numerator = 0, int denominator = 1);
	private:
		int n, d;
		//friend const Rational operator*(const Rational &lhs, const Rational &rhs);
	};

}
