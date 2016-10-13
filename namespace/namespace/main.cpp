#include<iostream>
namespace pri {
	void compute(){}
	void compute(const void*){}
}
using namespace pri;
void compute(int a){}
void compute(double a,double=3.15){}
void compute(char *a,char* =0){}
void main() {
	compute(0);
}