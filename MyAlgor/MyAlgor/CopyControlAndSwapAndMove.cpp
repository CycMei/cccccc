#include<string>
//////////////////////////////////////
/////类值
class HasPtr {
public:
	friend void swap(HasPtr&,HasPtr&);
	HasPtr(const std::string &s = std::string()) :ps(new std::string()), i(0) {

	}
	HasPtr(const HasPtr &p) :ps(new std::string(*p.ps)), i(p.i) {

	}
	HasPtr &operator=(const HasPtr&);
	//HasPtr &operator=(HasPtr);
	~HasPtr() {
		delete ps;
	}
private:
	std::string *ps;
	int i;
};
HasPtr &HasPtr::operator=(const HasPtr &item) {
	std::string *newp = new std::string(*item.ps);
	delete this->ps;
	this->ps = newp;
	this->i = item.i;
	return *this;
}
//HasPtr &HasPtr::operator=(HasPtr item){
//	swap(*this, item);
//	return *this;
//}
//////////////////////////////////////
/////类指针
class CopyHasPtr {
private:
	std::string *ps;
	int i;
	std::size_t *use;
public:
	CopyHasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0), use(new std::size_t(1)) {

	}
	CopyHasPtr(const CopyHasPtr &p) :ps(p.ps), i(p.i), use(p.use) {
		++*use;
	}
	CopyHasPtr &operator=(const CopyHasPtr&);
	~CopyHasPtr();
};
CopyHasPtr &CopyHasPtr::operator=(const CopyHasPtr &item) {
	++*item.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = item.ps;
	i = item.i;
	use = item.use;
	return *this;
}
CopyHasPtr::~CopyHasPtr() {
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}
//////////////////////////////////////
/////swap
inline void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}
//////////////////////////////////////
/////move
class StrVec {
public:
	StrVec(StrVec&&) noexcept;
	StrVec &operator=(StrVec&&) noexcept;
private:
	int *pi;
	std::string *ps;
	double *pd;
};
StrVec::StrVec(StrVec &&item) noexcept:pi(item.pi),ps(item.ps),pd(item.pd) {
	item.pi = 0;
	item.ps = nullptr;
	item.pd = NULL;
}
StrVec &StrVec::operator=(StrVec &&item) noexcept {
	if (this != &item) {
		pi = item.pi;
		ps = item.ps;
		pd = item.pd;
		pi = 0;
		ps = nullptr;
		pd = NULL;
	}
	return *this;
}
