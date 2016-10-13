#include<list>
#include<boost\any.hpp>
using boost::any_cast;
void append_int(std::list<boost::any> &values, int value) {
	boost::any to_append = value;
	values.push_back(to_append);
}
void append_string(std::list<boost::any> &values, const std::string &value) {
	values.push_back(value);
}
void append_char_ptr(std::list<boost::any> &values, const char *value) {
	values.push_back(value);
}
void append_any(std::list<boost::any> &values, const boost::any &value) {
	values.push_back(value);
}
void append_nothing(std::list < boost::any > &values) {
	values.push_back(boost::any());
}
bool is_empty(const boost::any &operand) {
	return operand.empty();
}
bool is_int(const boost::any &operand) {
	return operand.type() == typeid(int);
}
bool is_char_ptr(const boost::any &operand) {
	try {
		any_cast<const char*>(operand);
		return true;
	}
	catch (const boost::bad_any_cast&) {
		return false;
	}
}
bool is_string(const boost::any &operand) {
	return any_cast<std::string>(&operand);
}
void count_all(std::list<boost::any> & values, std::ostream & out)
{
	out << "#empty == "
		<< std::count_if(values.begin(), values.end(), is_empty) << std::endl;
	out << "#int == "
		<< std::count_if(values.begin(), values.end(), is_int) << std::endl;
	out << "#const char * == "
		<< std::count_if(values.begin(), values.end(), is_char_ptr) << std::endl;
	out << "#string == "
		<< std::count_if(values.begin(), values.end(), is_string) << std::endl;
}
