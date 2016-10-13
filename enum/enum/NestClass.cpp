#include<set>
#include<string>
#include<memory>
#include<vector>
#include<iostream>
class TextQuery {
public:
	class QueryResult;
	using line_no = std::vector<std::string>::size_type;
	QueryResult query(const std::string&) const;
};
class TextQuery::QueryResult {
	friend std::ostream &print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string, std::shared_ptr<std::set<line_no>>, std::shared_ptr<std::vector<std::string>>);
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> files;
	static int static_mem;
};
TextQuery::QueryResult::QueryResult
(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f):sought(s),lines(p),files(f){}
int TextQuery::QueryResult::static_mem = 1024;
//TextQuery::QueryResult TextQuery::query(const std::string &sought) const {
//	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
//}
int myss;
void myTest() {
	enum MyEnum {
		first
	};
	int ss=2;
	int static ssc;
	class myClass {
	public:
		int returint() {
			return MyEnum::first;
		}
	private:
	};
}
int a, val;
void foo(int val) {
	static int si;
	enum loc {
		a=1024,
		b
	};
	struct Bar {
		loc locVal;
		int barVal;
		void fooBar(loc l = a) {
			barVal = ::val;
			barVal = si;
			locVal = b;
		}
	};
}
typedef unsigned int Bit;
class File {
	Bit mode : 2;
	Bit modifie : 1;
	Bit prot_owner : 3;
public:
	enum modes {
		READ=01,
		WRITE=02,
		EXECUTE=03
	};
	File &open(modes);
	void close();
	void write();
	bool isRead() const;
	void setWrite();
};
void File::write() {
	modifie = 1;
}
void File::close() {
	if (modifie) {

	}
}
File &File::open(File::modes m) {
	mode |= READ;
	if (m&WRITE) {

	}
	return *this;
}
