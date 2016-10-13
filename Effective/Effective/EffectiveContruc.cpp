#include<vector>
#include<string>
namespace contructor {
	template<typename T>
	class NameObject {
	private:
		std::string nameValue;
		T objectValue;
	public:
		NameObject(const char *name, const T &value) {}
		NameObject(const std::string &name, const T &value) {}
	};
	void test() {
		NameObject<int> no1("smallest prime number", 2);
		NameObject<int> no2(no1);
	}
	template<typename T>
	class copyNameObject {
	private:
		std::string &copyNameValue;
		const T objectValue;
	public:
		copyNameObject(std::string &name,const T &value):copyNameValue(name),objectValue(value){}
	};
	void test2() {
		std::string newDog("Persephone");
		std::string lodDog("Satch");
		copyNameObject<int> p(newDog, 2);
		copyNameObject<int> s(lodDog, 36);
		//p = s;
	}
	class TimeKeeper {
	public:
		TimeKeeper(){}
		virtual ~TimeKeeper() {

		}
	};
	class AtomicClock :public TimeKeeper {};
	class WaterClock :public TimeKeeper {};
	class WristWatch:public TimeKeeper{};
	TimeKeeper *getTimeKeeper() {
		return new TimeKeeper();
	}
	void test1() {
		TimeKeeper *ptk = getTimeKeeper();
		delete ptk;
	}
	class Point {
	private:
		int x, y;
	public:
		Point(int xCoord, int yCoord):x(xCoord),y(yCoord){}
		~Point() {

		}
	};
	class AWOW {
	public:
		virtual ~AWOW() = 0;
	};
	class Widget {
	public:
		~Widget() {

		}
		void dcSomething() {
			std::vector<Widget> v;
		}
	};
	class DBConnection {
	public:
		void close(){}
		static DBConnection create();
	};
	class DBConn {
	private:
		DBConnection db;
		bool closed;
	public:
		void close() {
			db.close();
			closed = true;
		}
		~DBConn() {
			if (!closed) {
				try {
					db.close();
				}
				catch (...) {

				}
			}
		}
	};



	class Transaction {
	public:
		Transaction() {
			logTransaction();
		}
		virtual void logTransaction() const = 0;
	};
	class BuyTRansaction :public Transaction {
	public:
		virtual void logTransaction() const;
	};
	class SellTransaction :public Transaction {
	public:
		virtual void logTransaction() const;
	};
	void test4() {
		//BuyTRansaction b;
	}

}