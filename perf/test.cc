#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int another_costly(int x)
{
	double sum = 0;
	for (int i=2; i<x; ++i)
		sum += log((double)x);

	return sum;
}

int main()
{
	int sum = 0;

	for (int i=0; i<10000; ++i)
		sum += another_costly(i);

	cout << sum << endl;
}
