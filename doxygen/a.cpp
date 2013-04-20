#include <iostream>

class cl{
	public:
int a()
{
	return 1;
}

void b()
{
	while (a());
}
};

int main()
{
	cl c;
	c.b();
}
