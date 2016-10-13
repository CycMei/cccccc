#include"StrBlob.h"
StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()){}
StrBlob::StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}
void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}
std::string &StrBlob::front() {
	check(0, "ssss");
	return data->front();
}
std::string &StrBlob::front() const {
	check(0, "ssss");
	return data->front();
}
std::string &StrBlob::back() {
	check(0, "sssss");
	return data->back();
}
std::string &StrBlob::back() const {
	check(0, "sssss");
	return data->back();
}
void StrBlob::pop_back() const {
	check(0, "sssd");
	data->pop_back();
}
