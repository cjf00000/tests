#include <random>
#include <vector>
#include <mutex>
#include <stdint.h>
#include <thread>
#include <iostream>
#include <atomic>
using namespace std;

// Thread safe singleton
class Singleton
{
private:
	Singleton(){ a = 0; }

	// Disable copy and assignment and destruction
	Singleton(Singleton&) = delete;
	void operator = (Singleton&) = delete;
	~Singleton(){}

public:
	static Singleton& getInstance(){
		static Singleton instance_;
		return instance_;
	};
	void add(int x){ a+= x;}
	int get(){ return a; }

private:
	atomic<int> a;
};

const int times = 1000;
const int num_threads = 10000;

int main()
{
	vector<thread> threads;
	for (int t = 0; t < num_threads; t++)
	{
		threads.push_back(thread([](){
			for (int i = 0; i < times; ++i)
				Singleton::getInstance().add(1);
			}));
	}

	for (auto &thread: threads)
		thread.join();

	cout << Singleton::getInstance().get() << endl;
}
