#include <iostream>
#include <condition_variable>
#include <thread>
using namespace std;

condition_variable cond_var;
mutex m;

int main()
{
	int value = 0;
	bool nofified = false;

	thread reporter( [&]() {
			unique_lock<mutex> lock(m);

			while (!nofified) {
				cond_var.wait(lock);
				puts("Awake");
			}
			cout << "The value is " << value << endl;
	});

	thread producer( [&]() {
		value = 200;
		nofified = true;
		cond_var.notify_one();
	});

	reporter.join();
	producer.join();
}
