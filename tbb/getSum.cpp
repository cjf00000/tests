#include <iostream>
#include <algorithm>
#include <cmath>
#include <tbb/parallel_reduce.h>
#include <tbb/blocked_range.h>
using namespace std;
using namespace tbb;

const int N = 100000000;
int a[N];

class SumArray
{
	int *a;
public:
	int sum;

	void operator() (const blocked_range<size_t> &r)
	{
		cout << "Begin="<<r.begin() << '\t' << "End="<<r.end() << "\tThis=" << (unsigned long long)this << endl;

		for (size_t i=r.begin(); i!=r.end(); ++i)
		{
			// Do a costly operation
			sum += int(log((double)a[i]));

		}
		cout << "Finished\tThis=" << (unsigned long long)this << endl;
	}

	SumArray(SumArray &x, split)
		: a(x.a), sum(0)
	{
		cout << "Split!" << (unsigned long long)this << endl;
	}

	void join(SumArray &x)
	{
		sum += x.sum;
	}	

	SumArray(int *a)
		: a(a), sum(0)
	{}

};

int main()
{
	for (size_t i=0; i<N; ++i)
	{
		a[i] = rand();
	}

	SumArray sa(a);
	parallel_reduce(blocked_range<size_t>(0, N, 10000000), sa);

	cout << sa.sum << endl;
}
