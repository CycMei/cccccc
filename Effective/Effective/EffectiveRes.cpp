#include<string>
#include<vector>
#include<memory>
#include<mutex>
namespace res {
	class Investnent{};
	Investnent *createInvestnent() {
		return new Investnent();
	}
	void f() {
		std::unique_ptr<Investnent> pInv(createInvestnent());
	}


	


}
