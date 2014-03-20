#include <thread>
#include <atomic>
#include <iostream>
#include <vector>
using namespace std;

const int num_workers = 4;
const int num_elements = 100;

int main()
{
	vector<int> elem;
	for (int i = 0; i < num_elements; ++i)
		elem.push_back(i);

	vector<thread> threads;
	atomic<int> cnt;
	cnt = 0;
	for (int t = 0; t < num_workers; ++t)
		threads.push_back(thread([&](){
			int ind;
			while ( (ind = cnt++) < num_elements )
			{
				elem[ind] *= 2;
			}
		}));

	for (auto &t: threads)
		t.join();

	for (auto i: elem)
		cout << i << endl;
}
