#include "mkarray.h"
#include <iostream>
using namespace std;

int main()
{
	mkarray a = ( mkarray(), 3, 5, 6 );
	cout << a._data[0] << a._data[1] << a._data[2] << endl;
}
