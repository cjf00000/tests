#include <iostream>
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
	cout << add(0, 100000000) << endl;
}
