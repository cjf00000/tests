#include <iostream>
#include <algorithm>
using namespace std;

int costly(int x, int y)
{
	int sum = 0;
	for (int i=0; i<x; ++i)
		for (int j=0; j<y; ++j)
			sum += i*j;

	return sum;
}

int another_costly(int x, int y)
{
	int sum = 0;
	for (int i=0; i<x; ++i)
		for (int j=0; j<y; ++j)
			sum += i*j;

	return sum;
}

int main()
{
	int sum = 0;

	for (int i=0; i<1000; ++i)
		if ((rand()&1) == 1)
			sum += costly(i, i*2);
		else
			sum += another_costly(i, i/2);

	cout << sum << endl;
}
