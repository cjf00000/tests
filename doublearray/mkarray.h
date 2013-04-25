#ifndef __LENGTH_OF
#define __LENGTH_OF

#include <vector>
using namespace std;

class mkarray
{
public:
	mkarray();
	mkarray& operator , (double a)
	{
		_data.push_back(a);
		return *this;
	}

public:
	vector<double> _data;
};

#endif
