#include<string>
#include<iostream>
using std::string;
//定义和初始化string
namespace init {
	void str() {
		string s1;				//默认初始化，s1是个空字符串
		string s2 = s1;			//s2是s1的副本，等价： string s2(s1);
		string s3 = "hiya";		//s3是该字符串字面值的副本，等价：string s3("hiya");
		string s4(10, 'c');		//s4的内容是10个c，多个初始值只能用直接初始化，不过拷贝初始化也可以：string s4=string(10,'c');有个临时对象
	}
	void extend() {
		const char *cp = "Hello Word!!!";	//以空字符结束的数组
		char noNull[] = { 'H','i' };		//不以空字符结束的数组
		string s1(cp);						//拷贝cp中的字符知道遇到空字符
		string s2(noNull, 2);				//从noNull中拷贝2个字符，前2个字符的拷贝
		//string s3(noNull);				//未定义，noNull不是以空字符结束的数组
		string s4(cp + 6, 5);				//从cp[6]开始拷贝5个字符
		string s5(s1, 6, 5);				//从s1[6]开始拷贝5个字符
		string s6(s1, 6);					//从cp[6]开始拷贝直到s1的末尾，如果第二个参数大于第一个参数的size(),构造函数未定义
		string s7(s1, 6, 20);				//从s1[6]开始最多拷贝到s1的末尾，如果第二个参数大于第一个参数的size(),构造函数未定义
		string s8(s1, 16);					//如果第二个参数大于第一个参数的size(),构造函数未定义，抛出out_of_range
	}
};
//操作
namespace contr {
	//ios
	void ios(){
		string s;
		std::cin >> s;				//将string对象读入s，返回cin。string对象会自动忽略开头的空白，从一个真正的字符读取，直到遇见下一个空白
		std::cout << s << std::endl;//将s写到cout中，返回cout
	}
	void mgetline() {
		string line;
		//std::getline：参数非别是is,string类型对象。返回流参数，为了保留输入时的空白符
		//从流中读取内容直到遇见换行符，换行符也被读进来。
		//然后将所读内容存入到string对象去，换行符不存。
		//getline遇见换行符就结束读取操作，并返回结果，如果一开始是换行符，结果是空string
		while (std::getline(std::cin, line)) {
			std::cout << line << std::endl;
		}
	}
	void othercontr() {
		string s1("hello word");
		s1.empty();		//s1为空返回true，否则返回false
		string::size_type count=s1.size();		//s1对象中的字符个数,size_type：无符号类型，有sting size()函数的地方不要使用int
	}
	bool comparestr() {
		//sting 比较运算符：逐一比较string对象中的字符，对大小写敏感
		//==,!=：2个string对象的长度和所包含的字符也相同，否则不等
		//<,<=,>,>=：字典顺序
		//1.如果2个string对象的长度不同，而且较短的对象的每个字符都与较长的string对象对应位置上的字符相同，则短的string小于长的string对象
		//2.如果2个string对象在某些位置上不一致，结果就是string对象中第一对相异字符比较结果
		string str = "Hello";
		string phrase = "Hello World";
		string slang = "Hiya";
		if (str < phrase)
			return true;
		if (phrase < slang)
			return true;
	}
	void opratoreuql() {
		string str(10, 'c'), stc;
		stc = str;				//对象赋值
		string s1 = "hello, ", s2 = "world\n";
		string s3 = s1 + s2;	//对象相加
		s1 += s2;
		//字面值和string对象，+号两侧的运算对象至少有一个是string对象
		string s4 = s1 + ",";
	}
	void msubstr() {
		//substr 返回一个string，是原始的一部分或者全部的拷贝，可以提供一个开始位置和计数值
		string s("hello world");
		string s2 = s.substr(0, 5);		//从s[0]开始拷贝5个
		string s3 = s.substr(6);		//从s[6]拷贝到末尾
		string s4 = s.substr(6, 11);	//从s[6]最多拷贝到末尾
		string s5 = s.substr(12);		//其实位置超过size()，抛出out_of_range
	}
	void minsert() {
		string s("hello world");
		s.insert(s.size(), 5, '!');		//从s.size()之前插入5个!;接受下标的返回s的引用，接受迭代器的返回指向第一个字符插入的迭代器
		s.erase(s.size() - 5, 5);		//删除从s.szie()-5开始的5个字符，返回一个指向s的引用
		const char *cp = "skdlwkdffkdkddkd";
		s.assign(cp, 7);				//将s中的字符串替换为cp指向的地址开始的7个字符，返回引用
		s.insert(s.size(), cp + 7);		//插入cp+7之前的字符
		string s2 = "dwddd";
		s.insert(0, s2);
		s.insert(0, s2, 0, s2.size());
	}
	void mappend() {
		string s("c++ primer"), s2 = s;
		s2.append("dksl");				//在s2的末尾插入字符，返回引用
	}
	void mreplace() {
		string s("c++ primer"), s2 = s;
		s2.replace(2, 4, "dda");		//删除2开始的4个字符，但新增加字符 返回引用
	}
	//还有很多很多 懒得写
};