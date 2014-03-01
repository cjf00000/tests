#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

int cnt = 0;
mutex cnt_mutex;

void add(int start, int end)
{
	for (int i=start; i<end; ++i)
	{
		cnt_mutex.lock();
		cnt += i;
		cnt_mutex.unlock();
	}
}

int main()
{
	vector<thread> threads;
	for (int i=0; i<2; ++i)
	{
		threads.push_back(thread(&add, i*50000000, (i+1)*50000000));
	}

	for (auto &thread : threads)
		thread.join();

	cout << cnt << endl;
}
