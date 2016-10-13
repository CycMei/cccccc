#include<atomic>
namespace flag {
	void test() {
		std::atomic_flag f = ATOMIC_FLAG_INIT;
		f.clear(std::memory_order_release);
		bool x = f.test_and_set(std::memory_order_seq_cst);

	}
	class spinlock_mutex {
	private:
		std::atomic_flag flag;
	public:
		spinlock_mutex() :flag(ATOMIC_FLAG_INIT){}
		void lock() {
			while (flag.test_and_set(std::memory_order_acquire))
				;
		}
		void unlock() {
			flag.clear(std::memory_order_release);
		}
	};
	void test2() {
		std::atomic<bool> b(true);
		b = false;
		std::atomic<bool> bb;
		bool x = bb.load(std::memory_order_acquire);
		bb.store(true);
		x = bb.exchange(false, std::memory_order_acq_rel);
		bool expected = false;
		while (!bb.compare_exchange_weak(expected, true) && !expected)
			;
		bb.is_lock_free();
	}
}
void main() {
	flag::test();
}