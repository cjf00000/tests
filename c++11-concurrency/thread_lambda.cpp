#include <thread>
#include <atomic>
#include <iostream>
#include <vector>
using namespace std;

const int num_workers = 100;
const int num_elements = 100000000;
atomic<long long> sum;

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
			bool sucess;
			int id = 0;
			long long local_sum = 0;

			while ( (id = cnt.fetch_add(1)) < num_elements){
				local_sum += id;
			}

			sum += local_sum;

		//	while (1) {
		//		do { 
		//			id = cnt;
		//		        sucess=atomic_compare_exchange_weak(&cnt,&id,id+1);
		//		} while(!sucess);
	
		//		if (id >= num_elements)
		//			break;

		//		local_sum += id;
		//	}

		//	sum += local_sum;
		}));

	for (auto &t: threads)
		t.join();

	cout << sum << endl;
	cout << (long long)(num_elements - 1) * num_elements / 2 << endl;
	cout << sizeof(int) << endl;
}
