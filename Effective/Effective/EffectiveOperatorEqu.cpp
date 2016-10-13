#include<string>
#include<vector>
class widget {
public:
	widget &operator=(const widget &rhs) {
		return *this;
	}
	widget &operator+=(const widget &rhs) {
		return *this;
	}
	widget &operator=(int rhs) {
		return *this;
	}
};
class Bitmap{};
class copyWidget{
public:
	copyWidget &operator=(const copyWidget &rhs) {
		if (this == &rhs)
			return *this;
		delete pb;
		pb = new Bitmap(*rhs.pb);
		return *this;
	}
private:
	Bitmap *pb;
};

void logCall(const std::string &funcName);
class Date{};
class Customer {
private:
	std::string name;
	//Date lastTransaction;
public:
	Customer(const Customer &rhs):name(rhs.name){}
	Customer &operator=(const Customer &rhs) {
		name = rhs.name;
		return *this;
	}
};
class PriorityCustomer :public Customer {
private:
	int priority;
public:
	PriorityCustomer(const PriorityCustomer &rhs):priority(rhs.priority),Customer(rhs){}
	PriorityCustomer &operator=(const PriorityCustomer &rhs) {
		priority = rhs.priority;
		Customer::operator=(rhs);
		return *this;
	}
};