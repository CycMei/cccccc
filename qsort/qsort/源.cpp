#include<iostream>
using namespace std;
int comperFunc(const void*, const void*);
void main() {

	int arr[7] = { 12,5,34,545,458,18,88 };
	for (int i = 1; i < 7; ++i) {
		int j = i;
		int target = arr[i];
		while (j > 0 && target < arr[j - 1]){
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = target;
	}
	for (auto c : arr) {
		cout << c << endl;
	}
	system("pause");
}
int comperFunc(const void *A, const void *B) {
	int *intA = (int *)(A);
	int *intB = (int *)(B);
	return *intA - *intB;
}