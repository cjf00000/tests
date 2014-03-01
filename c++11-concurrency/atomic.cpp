#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

atomic<int> cnt;
//int cnt = 0;

void add(int start, int end)
{
	for (int i=start; i<end; ++i)
		cnt += i;
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
