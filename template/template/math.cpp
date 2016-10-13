#include<functional>
#include<algorithm>
#include<cmath>
#include<type_traits>
extern unsigned int myINT;
//extern template int compare(const int&, const int& std::less<int> f=std::less<int>());
template<typename T> typename T::value_type top(){}
template<typename T, typename F = std::less<T>> int compare(const T &v1,const T &v2,F f=F()){
	if (f(v1, v2))
		return -1;
	if (f(v2, v1))
		return 1;
}
template<typename T> T f2(int &T) {}
template<typename T> inline T foo(T, unsigned int*);
template<typename T> T f4(T, T);
typedef char Ctype;
template<typename Ctype> Ctype f5(Ctype a);
template<typename T> int fcs() {
	T a = 0;
	return 0;
}
template<class T> int mVec(const T&,const T&){
	return 0;
}
void tesc() {
	//int res = mVec("hi", "word");
	int resc = mVec("bye", "dad");
}
namespace msd {
	template<typename T> void fcs(T, T) {}
	template<typename T1, typename T2> void fcss(T1, T2) {}
	int i = 0, j = 42, *p1 = &i, *p2 = &j;
	const int *cp1 = &i, *cp2 = &j;
	int *const cp3 = &i;
	void tescs() {
		fcs(p1, p2);
		fcss(p1, p2);
		fcs(cp1, cp2);
		fcss(cp1, cp2);
		fcs(p1, cp3);

	}
};
namespace ms {
	template<typename T1, typename T2, typename T3> T1 sum(T2, T3){
		return 0;
	}
	template<typename T3,typename T2,typename T1> T1 sums(T2,T3){
		return 0;
	}
	void test() {
		int i=0, lng=i;
		auto re=sum<long long>(i, lng);
		auto res = sums<long long,int,long>(i, lng);
	}
	template<typename T> T max(const T &a, const T &b) {
		return a > b ? a : b;
	}
	template<typename T> auto fcn(T beg, T end)->typename std::remove_reference<decltype(*beg)>::type {
		return *beg;
	}
	int i = 0;
	int &re = i;
	int &cc = re;
	int res() {
		return re;
	}
	//std::remove_reference<int&&>::type a = 0;
	//std::add_const<int&>::type aa;
	//std::add_const<const int> add;
	//std::remove_extent<int[3]> adc;
	
};
