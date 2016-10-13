#include<iostream>
#include<vector>
#include<type_traits>
#include<vld.h>
template<typename T1,typename T2>
auto ComMatrixAdd(std::vector<std::vector<T1>> t1,std::vector<std::vector<T2>> t2)
->std::vector<std::vector<typename std::conditional<sizeof(T1) >= sizeof(T2), T1, T2>::type>>{
	if (t1.empty() || t2.empty())
		return{ {NULL} };
	if (t1.size() != t2.size())
		return{ { NULL } };
	if (t1.at(0).size() != t2.at(0).size())
		return{ { NULL } };
	using resType = typename std::conditional<sizeof(T1) >= sizeof(T2), T1, T2>::type;
	std::vector<std::vector<resType>> addVec;
	for (size_t i = 0; i != t1.size(); ++i) {
		std::vector<resType> tempVec;
		for (size_t j = 0; j != t1[i].size(); ++j) {
			auto resc = t1[i][j] + t2[i][j];
			tempVec.push_back(resc);
		}
		addVec.push_back(tempVec);
	}
	return addVec;
}
template<typename T1,typename T2>
auto MatrixAddInstance(std::vector<std::vector<T1>> t1, std::vector<std::vector<T2>> t2)
->std::vector<std::vector<typename std::conditional<sizeof(T1) >= sizeof(T2), T1, T2>::type>>{
	auto addVec=ComMatrixAdd(t1,t2);
	return addVec;
}
template<typename T1,typename T2,typename... Args>
auto MatrixAddInstance(std::vector<std::vector<T1>> t1,std::vector<std::vector<T2>> t2,Args... rest)
->std::vector<std::vector<typename std::conditional<sizeof(T1) >= sizeof(T2), T1, T2>::type>>{
	auto addVec= ComMatrixAdd(t1, t2);
	return MatrixAddInstance(addVec, rest...);
}
void test(){
	std::vector<std::vector<double>> a{  };
	std::vector<std::vector<int>> b{ { 1, 2 },{ 1,2 } };
	std::vector<std::vector<int>> c{ { 1, 2 },{ 1,2 } };
	auto result=MatrixAddInstance(a, b,c);
	if (!result.empty()) {
		for (auto c : result) {
			for (auto cc : c) {
				std::cout << cc << std::endl;
			}
		}
	}
}
