#include <iostream>
#include <armadillo>
#include <ctime>

using namespace std;
using namespace arma;

#define tic timer.tic();
#define toc cerr << timer.toc() << endl;

int main(int argc, char** argv)
{
    int m = 1000;
    int n = 1000;

    mat A = randu<mat>(m, n);
    mat B = randu<mat>(m, n);

    wall_clock timer;

    double *c = new double[m*n];
		        
    puts("begin");
    mat C = A*B.t();
    puts("end");

    tic
    double sum = 0;
    for (int i=0; i<m; ++i)
	    for (int j=0; j<n; ++j)
		    sum += C(i, j);
    toc

    tic
    for (int j=0; j<n; ++j)
        for (int i=0; i<m; ++i)
		    sum += C(i, j);
    toc
	   
    tic
    double *Cmem = C.memptr();
    for (int j=0; j<n; ++j)
	    for (int i=0; i<m; ++i)
		    sum += Cmem[i+j*m];
    toc

    tic
    double *cmem = C.memptr();
    for (register int j=0; j<n; ++j)
	    for (register int i=0; i<m; ++i)
		    sum += cmem[i+j*m];
    toc

    tic
    for (int i=0; i<m; ++i)
	    for (int j=0; j<n; ++j)
		    sum += c[i*n+j];
    toc    

    cerr << sum << endl;

    mat D(2, 2);
    D << 1 << 2 << endr 
      << 3 << 4 << endr;

    cerr << D << endl;

    for (int i=0; i<4; ++i)
	    cerr << D.memptr()[i] << '\t';
    cerr << endl;

    const int len = 10000;
    double *a = new double[len]; 
    double *b = new double[len];
    tic;
    for (int i=0; i<100000; ++i)
    {
	    a[rand()%len] = 3;
	    for (int j=0; j<len; ++j)
		    sum += a[j] * b[j];
    }
    toc;

    vec av(len);
    vec bv(len);
    for (int i=0; i<len; ++i)
    {
	    av(i) = rand();
	    bv(i) = rand();
    }
    tic;
    for (int i=0; i<100000; ++i)
    {
	    av[rand()%len] = 3;
	    sum += dot(av, bv);
    }
    toc;

    cerr << sum << endl;
			  
    return 0;
}
