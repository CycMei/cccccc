#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
namespace ss {
	struct PersonInfo {
		std::string name;
		std::vector<std::string> phones;
	};
	void printPer() {
		std::string line, word;
		std::vector<PersonInfo> people;
		while (std::getline(std::cin, line)) {
			PersonInfo info;
			std::istringstream record(line);
			record >> info.name;
			while (record >> word) {
				info.phones.push_back(word);
			}
			people.push_back(info);
		}
		for (std::vector<PersonInfo>::iterator beg = people.begin(); beg != people.end(); ++beg) {
			std::cout << beg->name << "  ";
			for (std::vector<std::string>::iterator be = beg->phones.begin(); be != beg->phones.end(); ++be) {
				std::cout << *be << "  ";
			}
			std::cout << std::endl;
		}
	}
	void printss() {
		std::vector<std::string> vec;
		std::string s;
		std::string file("temp.txt");
		std::ifstream in;
		in.open(file, std::ifstream::in);
		if (in) {
			while (in >> s) {
				vec.push_back(s);
			}
			std::istringstream is;
		}
	}
	void injia() {
		std::string file("cyc");
		std::ifstream jin;
		jin.open(file, std::ifstream::in|std::ifstream::ate);
		if (jin) {

		}
		else {
			std::cout << "fail" << std::endl;
			return;
		}
	}
}

namespace fs {
	std::string file("temp.txt");
	void scin() {
		std::ifstream ins(file, std::ifstream::in);
		std::vector<std::string> sc;
		if (ins) {
			std::string tempStr;
			//while (std::getline(ins, tempStr)) {
			//	sc.push_back(tempStr);
			//}
			while (ins>>tempStr) {
				sc.push_back(tempStr);
			}
		}
		else {
			std::cout << "¶ÁÈ¡Ê§°Ü" << std::endl;
			return;
		}
		for (auto c : sc) {
			std::cout << c << std::endl;
		}
	}
	void app() {
		std::ofstream out(file);
		std::ofstream out1(file, std::ofstream::out);
		std::ofstream out2(file, std::ofstream::out | std::ofstream::trunc);
		std::ofstream out3(file, std::ofstream::app);
		std::ofstream out4(file, std::ofstream::out | std::ofstream::app);
		std::ofstream out5;
		out5.open(file);
		out5.close();
		out5.open(file, std::ofstream::out | std::ofstream::app);
		out5.close();
	}
}
void main() {
	ss::injia();

}