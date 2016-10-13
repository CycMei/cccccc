
namespace design {
	struct Day {
		explicit Day(int d) :val(d) {}
		int val;
	};
	struct Month {
		explicit Month(int m) :val(m) {}
		int val;
	};
	struct Year {
		int val;
		explicit Year(int y) :val(y) {}
	};
	class Date {
	public:
		Date(const Month &m, const Day &d, const Year &y) {}
	};
	void test() {
		Date d(Month(3), Day(30), Year(1995));
	}
}
