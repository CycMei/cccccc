#include<list>
#include<string>
#include<vector>
#include<iostream>
namespace init {
	void test() {
		int x = 0;
		const char *text = "A c";
		double d;
		std::cin >> d;
	}
	class PhoneNumber{};
	class ABEntry {
	private:
		std::string theName;
		std::string theAddress;
		std::list<PhoneNumber> thePhones;
		int numTimesConsulted;
	public:
		ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones)
			:theName(name), theAddress(address), thePhones(phones), numTimesConsulted(0){}
		ABEntry() :theName(), theAddress(), thePhones(), numTimesConsulted(0){}
	};

	//���ڶ�����뵥Ԫ��ͬ��non local static ��ʼ��˳����ȷ�������ԣ�
	class FileSystem{};
	inline FileSystem &tfs() {
		static FileSystem fs;
		return fs;
	}
}