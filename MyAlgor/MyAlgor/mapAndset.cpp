#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<utility>
#include<fstream>
std::map<std::string, std::size_t> word_count;
std::set<std::string> exclude = { "the","but","and","or","an","a","The","But","And","Or","An","a" };
std::map<std::string, std::string> authors = { {"Joyce","James"},{"Austen","Jane"},{"Dickens","Charles"} };
std::vector<int> ivec;
void testVec() {
	for (std::vector<int>::size_type i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	std::set<int> iset(ivec.cbegin(), ivec.cend());
	std::multiset<int> miset(ivec.cbegin() , ivec.cend());
	std::cout << ivec.size() << std::endl;//20
	std::cout << iset.size() << std::endl;//10
	std::cout << miset.size() << std::endl;//20
}
void mapHome() {
	std::map<std::string, std::vector<std::string>> imap{
		{"Chen",{"cone","ctwo","cthree"}},
		{"Luo",{"lone","ltwo","lthree"}}
	};
	//去处重复
}
class Sales_data {
private:
	int i;
public:
	int isbn() const {
		return i;
	}
};
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}
Sales_data s1;
Sales_data s2;
void dwedd() {
	std::map<std::string, std::list<int>> mlist{
		{"vdsw",{1,3,54}},
		{"ksdjfke",{2,4,543,4}}
	};
	std::map<Sales_data, std::string, decltype(compareIsbn)*> msslist{
		{ { s1,"vdsw" },
		{ s2, "ksdjfke" } },
		compareIsbn
	};
	std::multiset<Sales_data, decltype(compareIsbn)*> bookstore{ { s1,s2 },compareIsbn };
	std::multimap<Sales_data, int, decltype(compareIsbn)*> sdkw(compareIsbn);

	std::list<int> ilist{ 3,2 };
	std::map<std::vector<int>::iterator, int> itei{ { ivec.begin(),3 } };
	//错误，list的迭代器没有比较操作
	//std::map<std::list<int>::iterator, int> ilisst{ {ilist.begin(),2} };
}
std::pair<std::string,int> pair(std::vector<std::string> &v) {
	std::pair<std::string, std::string> anon;
	std::pair<std::string, std::size_t> word_count;
	std::pair<std::string, std::vector<int>> line;
	std::pair<std::string, std::string> anthor{ "James","joyce" };
	std::cout << anthor.first << anthor.second << std::endl;
	std::vector<std::pair<std::string, int>> vpair{ {"ssf",3},{"sddc",4},std::make_pair("sddw",3) };
	std::set<std::string>::value_type v1("dd");
	std::set<std::string>::key_type v2("sdd");
	std::map<std::string, int>::key_type v4("kdkw");
	std::map<std::string, int>::value_type v5 = std::make_pair("ddww", 32);
	std::map<std::string, int>::mapped_type v6(3);
	std::map<std::string, std::size_t>::iterator map_it = ::word_count.begin();
	std::map <std::string, std::size_t>::value_type &rf = *map_it;
	std::map <std::string, std::size_t>::key_type first = (*map_it).first;
	std::map <std::string, std::size_t>::mapped_type secend = (*map_it).second;
	std::set<std::string> ise;
	ise.emplace("sdw");
	if (!v.empty())
		return{ v.back(),v.back().size() };
	else
		return std::pair<std::string, int>();
	return std::make_pair(v.back(), v.back().size());
}
void kljhd(){
	std::set<std::string>::const_iterator set_it = exclude.cbegin();
	while (set_it != exclude.cend()) {
		std::cout << *set_it << std::endl;
		++set_it;
	}
	std::map<int, std::vector<int>>::mapped_type mapvec{ 23,32 };
}
namespace insert {
	std::vector<int> ivec = { 2,4,6,8,2,4,6,8 };
	std::set<int> set2;
	std::map<std::string, std::size_t> word_count;
	void swk() {
		set2.insert(ivec.cbegin(), ivec.cend());
		set2.insert({ 1,3,5,7 });
		word_count.insert({ "word",1 });
		word_count.insert(std::make_pair("sw", 3));
		word_count.insert(std::pair<std::string, std::size_t>("swdd", 3));
		word_count.insert(std::map < std::string, std::size_t >::value_type("sdw", 23));
	}
	void count() {
		std::map<std::string, std::size_t> word_count;
		std::string word;
		while (std::cin >> word) {
			std::pair<std::map<std::string,std::size_t>::iterator, bool> ret = word_count.insert({ word,1 });
			if (!ret.second)
				++ret.first->second;
		}
	}
};
namespace find {
	std::set<int> iset{ 0,1,2,3,4,5,6,7,8,9 };
	void sfds() {
		std::set<int>::const_iterator cons_set_it = iset.find(2);
		auto count=iset.count(2);
		std::string search_item("Alain de Bottom");
		std::size_t entries = authors.count(search_item);
		auto iter = authors.find(search_item);
		while (entries) {
			std::cout << iter->second << std::endl;
			++iter;
			--entries;
		}
		std::map<std::string, std::vector<int>> ssw{ { "sdkwk",{ 12,34 } } };
		std::map<std::string,std::vector<int>>::iterator itewd=ssw.find("sdkwk");
	}
};
namespace word{
	std::map<std::string, std::string> bulidMap(std::ifstream &map_file) {
		std::map<std::string, std::string> trans_map;
		std::string key;
		std::string value;
		while (map_file >> key&&std::getline(map_file, value)) {
			if (value.size() > 1)
				trans_map[key] = value.substr(1);
			else
				throw std::runtime_error("no rule for" + key);
		}
		return trans_map;
	}
	void word_transform(std::ifstream &map_file, std::ifstream &input) {
		auto trans_map = bulidMap(map_file);
	}
};
