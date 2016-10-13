#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include<vector>
#include<string>
#include<memory>
#include"StrBlob.h"
class StrBlobPtr {
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a,std::size_t sz=0):wptr(a.data),curr(sz){}
	std::string &deref() const;
	StrBlobPtr &incr();
};
#endif
