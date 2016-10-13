
#include<vector>
#include<string>
namespace MySwap {
	template<typename T>
	void swap(T &a, T &b) {
		T temp(a);
		a = b;
		b = temp;
	}
	class WidgetImpl {
	private:
		int a, b, c;
		std::vector<double> v;
	public:

	};
	template<typename T> class Widget {
	private:
		WidgetImpl *pImpl;
	public:
		Widget(const Widget &rhs){}
		Widget &operator=(const Widget &rhs) {
			*pImpl = *(rhs.pImpl);
			return *this;
		}
		void swap(Widget &other) {
			using std::swap;
			swap(pImpl, other.pImpl);
		}
	};
	template<typename T> void swap(Widget<T> &a, Widget<T> &b) {
		a.swap(b);
	}
}
void main() {

}