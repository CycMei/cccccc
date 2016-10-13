#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
class Scree {
public:
	typedef std::string::size_type pos;
	static const std::string Scree::*data() {
		return &Scree::contents;
	}
	const pos Scree::*getCur = &Scree::cursor;
	char get_cursor() const {
		return contents[cursor];
	}
	char get() const {
		return 'c';
	}
	char get(pos ht, pos wd) const {
		return 'c';
	}
	Scree &home(){
		return *this;
	}
	Scree &forward(){
		return *this;
	}
	Scree &back(){
		return *this;
	}
	Scree &up(){
		return *this;
	}
	Scree &down(){
		return *this;
	}
	using Action = Scree& (Scree::*)();
	enum Direction {
		HOME,
		FORWARD,
		BACK,
		UP,
		DOWN
	};
	Scree &move(Direction cm) {
		return (this->*Menu[cm])();
	}
private:
	std::string contents;
	pos cursor;
	pos height, width;
	static Action Menu[];
};
Scree::Action Scree::Menu[] = {
	&Scree::home,
	&Scree::forward,
	&Scree::back,
	&Scree::up,
	&Scree::down
};
Scree mySc, *pSc;
void tessaa() {
	mySc.*Scree::data();
	pSc->*Scree::data();
	char (Scree::*copy_get)() const = &Scree::get;
	char (Scree::*getC)() const = &Scree::get_cursor;
	char (Scree::*gets)(Scree::pos, Scree::pos) const = &Scree::get;
	using ACTION = char (Scree::*)(Scree::pos, Scree::pos) const;
	ACTION get=&Scree::get;
	(mySc.*copy_get)();
	(pSc->*copy_get)();
	Scree MY;
	MY.move(Scree::Direction::HOME);
	auto pmp = &Scree::get_cursor;
	pmp = &Scree::get;
}
void stsss() {
	std::vector<std::string*> pvec;
	std::function<bool(const std::string*)> fp = &std::string::empty;
	std::find_if(pvec.begin(), pvec.begin(), fp);
}