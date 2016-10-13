#include<functional>
#include<algorithm>
#include<vector>
#include<iostream>
#include<list>
#include<string>
#include<numeric>
#include<iterator>
#include<fstream>
namespace alg {
	void finds() {
		int val = 42;
		std::vector<int> vec{ 1,34,4,32,23,54 };
		std::vector<int>::const_iterator result=std::find(vec.cbegin(), vec.cend() - 2, val);
		if (result == vec.cend() - 2)
			std::cout << "²éÕÒÊ§°Ü" << std::endl;
		else
			std::cout << *result << std::endl;
	}
	void findArr() {
		int val = 134;
		int ia[]{ 23,23,134,432,21,3421 };
		auto result = std::find(std::begin(ia), std::end(ia), val);
		if (result == std::end(ia))
			std::cout << "²éÕÒÊ§°Ü" << std::endl;
		else
			std::cout << *result << std::endl;
	}
	void findCount() {
		int val = 2;
		std::vector<int> vec{ 23,34,3231,43,2,3,2,2,2 };
		std::size_t result= std::count(vec.cbegin(), vec.cend(), val);
		std::cout << result << std::endl;
		std::cout << std::endl;

		std::string vals("cyc");
		std::list<std::string> lStr{ "cyc","cyc","djds","ccsk" };
		std::size_t results = std::count(lStr.cbegin(), lStr.cend(), vals);
		std::cout << results << std::endl;
		std::cout << std::endl;
	}
	void numer() {
		std::vector<int> vec{23, 2, 23, 23, 2, 3232, 2};
		int sum = std::accumulate(vec.cbegin(), vec.cend(), 0);
		std::cout << sum << std::endl;
		std::cout << std::endl;
		std::vector<std::string> svec{ "skd", "dsd","dsdw" };
		std::string sums = std::accumulate(svec.cbegin(), svec.cend(), std::string(""));
		std::cout << sums << std::endl;
	}
	void equalStr() {
		std::vector<const char*> ros1{ "cyc","abc","cyc" };
		std::list<const char*> ros2{ "cyc","abc","cyc","ccc" };
		bool isEqual = std::equal(ros1.cbegin(), ros1.cend(), ros2.cbegin());
		std::cout << std::boolalpha << isEqual << std::endl;
	}
	void mfill() {
		std::vector<int> vec{ 1,23,4,2 };
		std::fill(vec.begin(), vec.begin() + vec.size() / 2, 10);
		for (auto c : vec) {
			std::cout << c << std::endl;
		}

		std::vector<int> vvec{ 2,2,3 };
		std::cout << vvec.size();
		std::fill_n(vvec.begin(), vec.size()-1, 0);
		for (auto cc : vvec) {
			std::cout << cc << std::endl;
		}
	}
	void backinsert() {
		std::vector<int> vec;
		std::back_insert_iterator<std::vector<int>> ise =std::back_inserter(vec);
		*ise = 100;
		for (auto c : vec)
			std::cout << c << std::endl;
	}
	void mcopy() {
		int a1[]{ 0,1,2,3,4,5,6,8,9 };
		int a2[sizeof(a1) / sizeof(*a1)];
		int *result=std::copy(std::begin(a1), std::end(a1), a2);
		for (auto c : a2) {
			std::cout << c << std::endl;
		}
		if (result == std::end(a2))
			std::cout << std::boolalpha<<true << std::endl;
	}
	void replacecopy() {
		std::vector<int> vec;
		std::vector<int> vvec{ 22,32,23,12,34 };
		std::replace_copy(vvec.cbegin(), vvec.cend(),std::back_inserter(vec), 22, 100);
		for (auto c : vvec) {
			std::cout << c << std::endl;
		}
		for (auto c : vec) {
			std::cout << c << std::endl;
		}
	}
	std::vector<std::string> vec{ "the","quick","red","fox","jumps","over","the","alow","red","turtle" };
	void msort(std::vector<std::string> &words=vec) {
		std::sort(words.begin(), words.end());
		std::vector<std::string>::iterator re=std::unique(words.begin(), words.end());
		words.erase(re, words.end());
	}
	bool isShorter(const std::string &s1, const std::string &s2) {
		return s1.size() < s2.size();
	}
	void lambdas() {
		//std::sort(vec.begin(), vec.end(), isShorter);
		std::stable_sort(vec.begin(), vec.end(), isShorter);
		for (auto c : vec) {
			std::cout << c << "  ";
		}
	}
	bool parti(const std::string &str) {
		if (str.size() >= 5)
			return true;
		return false;
	}
	void partlambda() {
		std::vector<std::string>::iterator res=std::partition(vec.begin(),vec.end(),parti);
		for (std::vector<std::string>::iterator beg = vec.begin(); beg != res; ++beg)
			std::cout << *beg << "  ";
	}
	void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
		msort();
		lambdas();
	}
	int (*f)() = []()->int {
		return 42;
	};
	void slskd() {
		std::stable_sort(vec.begin(), vec.end(), 
			[](const std::string &s1, const std::string &s2)->bool {
			return s1.size() < s2.size();
		});
		for (auto c : vec) {
			std::cout << c << "  ";
		}
	}
	void findif(std::size_t sz) {
		std::vector<std::string>::iterator res=std::find_if(vec.begin(), vec.end(), 
			[sz](const std::string &str)->bool{
			return str.size() >= sz;
		});
		if (res != vec.end())
			std::cout << *res << std::endl;
	}
	void foreach(std::size_t sz) {
		msort();
		std::stable_sort(vec.begin(), vec.end(), [](const std::string &s1, const std::string &s2)->bool {
			return s1.size() < s2.size();
		});
		findif(sz);
	}
	int (*ff)(int,int)=[](int a, int b)->int {
		return a + b;
	};
	void add(int a) {
		[a](int b)->int {
			return a + b;
		};
	}
	void fcn1() {
		std::size_t v1 = 42;
		auto f = [v1]()->int {
			return v1;
		};
		v1 = 0;
		int j = f();
	}
	void fcn2() {
		std::size_t v1 = 42;
		auto f2 = [&v1]()->int {
			return v1;
		};
		v1 = 0;
		int j = f2();
	}
	int(*ffc)();
	auto ret() {
		ffc = []()->int {
			return 32;
		};
		return ffc;
	}
	void sdlsd(std::size_t sz) {
		auto vs = std::find_if(vec.begin(), vec.end(), [=](const std::string &s)->bool {
			return s.size() >= sz;
		});
	}
	void fcn3() {
		std::size_t v1 = 42;
		auto f = [v1]() mutable->int {
			return v1++;
		};
		v1 = 0;
		int j = f();
	}
	void fcn4() {
		std::size_t v1 = 42;
		auto f = [&v1]()->int {
			return ++v1;
		};
		v1 = 0;
		int j = f();
	}
	void transfos() {
		std::vector<int> vecs{ 1,-2,3,-4,-3,2 };
		std::transform(vecs.begin(), vecs.end(), vecs.begin(), [](int i)->int {
			return i < 0 ? -i : i;
		});
		std::size_t n=std::count_if(vecs.begin(), vecs.end(), [](int i)->bool {
			return i < 0 ? true : false;
		});
		std::cout << n;
	}
	bool check_size(const std::string &s, std::string::size_type sz) {
		return s.size() >= sz;
	}
	void sldsw() {
		using std::placeholders::_1;
		auto check6 = std::bind(check_size, _1, 6);
		std::string s("hello");
		bool bl = check6(s);
		std::cout << bl << std::endl;
		int sz = 6;
		auto wc = std::find_if(vec.begin(), vec.end(), std::bind(check_size, _1, sz));
	}
	std::ostream &print(std::ostream &os, const std::string &s, char c) {
		return os << s << c;
	}
	void dsldkwl() {
		using std::placeholders::_1;
		std::for_each(vec.begin(), vec.end(), std::bind(print, std::ref(std::cout), _1, ' '));
	}
	void insertite() {
		std::vector<int> ves{ 1,2,3,4 };
		std::insert_iterator<std::vector<int>> res=std::inserter(ves,ves.begin());
		*res = 3;
		*res = 100;
		for (auto c : ves)
			std::cout << c << " ";
	}
	void frontInsert() {
		std::list<int> lst{ 1,2,3,4 }, lst2, lst3;
		std::copy(lst.begin(), lst.end(), std::front_inserter(lst2));
		for (auto c : lst2)
			std::cout << c << " ";
		std::cout << std::endl;
		std::copy(lst.begin(), lst.end(), std::inserter(lst3, lst3.begin()));
		for (auto c : lst3)
			std::cout << c << " ";
	}
	void uniqucopy() {
		std::vector<int> ves{ 1,2,3,2,3,1,2,3,3,4 };
		std::list<int> lst;
		std::sort(ves.begin(), ves.end());
		std::unique_copy(ves.begin(), ves.end(),std::back_inserter(lst));
		for (auto c : lst)
			std::cout << c << " ";
	}
	void minsersss() {
		std::vector<int> ves{ 1,2,3,4,5,6,7,8,9 }, v1;
		std::list<int> l2, l3;
		std::insert_iterator<std::vector<int>> r1 = std::inserter(v1, v1.begin());
		std::copy(ves.cbegin(), ves.cend(), r1);
		for (auto c : v1)
			std::cout << c << " ";
		std::cout << std::endl;
		std::back_insert_iterator<std::list<int>> r2 = std::back_inserter(l2);
		std::copy(ves.cbegin(), ves.cend(), r2);
		for (auto c : l2)
			std::cout << c << " ";
		std::cout << std::endl;
		std::front_insert_iterator<std::list<int>> r3 = std::front_inserter(l3);
		std::copy(ves.cbegin(), ves.cend(), r3);
	/*	for (auto c : l3)
			std::cout << c << " ";
		std::cout << std::endl;*/
	}
	void isterator() {
		std::istream_iterator<int> int_it(std::cin);
		std::istream_iterator<int> int_eof;
		std::ifstream in("afile");
		std::istream_iterator<std::string> str_it(in);
		std::vector<int> vs;
		while (int_it != int_eof)
			vs.push_back(*int_it++);
		for (auto c : vs)
			std::cout << c << " ";
		std::cout << vs.size();
	}
	void istreamAdd() {
		std::istream_iterator<int> in(std::cin), eof;
		std::cout << std::accumulate(in, eof, 0) << std::endl;
	}
	void ostreamtor() {
		std::vector<int> ves{ 1,2,3,4,5,6,7,8,9 }, v1;
		std::ostream_iterator<int> out_iter(std::cout, " ");
		for (int e : ves)
			*out_iter++ = e;
		std::cout << std::endl;
		std::copy(ves.begin(), ves.end(), out_iter);
	}
	void recbegin() {
		std::vector<int> ves{ 1,2,3,4,5,6,7,8,9 };
		std::sort(ves.rbegin(), ves.rend());
		for (std::vector<int>::const_reverse_iterator r_iter = ves.crbegin(); r_iter != ves.crend(); ++r_iter) {
			std::cout << *r_iter << " ";
		}
	}
	void rdkwks() {
		std::string s("cyc,abc");
		std::string::reverse_iterator res=std::find(s.rbegin(), s.rend(), ',');
		std::cout << std::string(s.rbegin(), res);
		std::cout << std::endl;
		std::cout << std::string(res.base(), s.end());
	}
	void listAlg() {
		std::list<int> lst1{ 1,23,42,323,4,32,4 };
		lst1.sort();
		std::list<int> lst2{ 23,2,235,6,4,43,21,23 };
		lst2.sort();
		lst1.merge(lst2);
		//lst1.remove(4);
		lst1.reverse();
		lst1.unique();
		for (auto c : lst1)
			std::cout << c << " ";
		std::cout << std::endl;
		std::cout << lst2.size();
	}
	void listsplice() {
		std::list<int> lst1{ 1,23,42,323,4,32,4 };
		std::list<int> lst2{ 23,2,235,6,4,43,21,23 };
		lst1.splice(lst1.end(), lst2);
		for (auto c : lst1)
			std::cout << c << " ";
		std::cout << std::endl;
		std::cout << lst2.size();
	}
	void listspsw() {
		std::list<int> lst1{ 1,23,42,323,4,32,4 };
		std::list<int> lst2{ 23,2,235,6,4,43,21,23 };
		lst1.splice(lst1.end(), lst2,lst2.begin());
		for (auto c : lst1)
			std::cout << c << " ";
		std::cout << std::endl;
		std::cout << lst2.size();
	}
};