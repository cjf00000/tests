#include <iostream>
#include <future>
#include <chrono>
#include <vector>
using namespace std;

int add(int start, int end)
{
	int cnt = 0;
	for (int i=start; i<end; ++i)
		cnt += i;

	return cnt;
}

int main()
{
	int cnt = 0;
	vector<future<int> > results;
	for (int i=0; i<2; ++i)
	{
		results.push_back(async(launch::async, &add, i*50000000, (i+1)*50000000));
	}

	for (auto &result : results)
		cnt += result.get();

	cout << cnt << endl;

	cout << "The thread returned " << cnt << endl;
	return 0;
}
