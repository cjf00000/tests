#include <math.h>
#include <mkl_scalapack.h>

#define MAX(x, y) ((x)>(y) ? (x):(y))

typedef MKL_INT MDESC[ 9 ];
const double  zero = 0.0E+0, one = 1.0E+0, two = 2.0E+0, negone = -1.0E+0;
const MKL_INT i_zero = 0, i_one = 1, i_four = 4, i_negone = -1;
const char    trans = 'N';

// Row major
// res = a*b, where a is n*k matrix, b is k*m matrix
void distributed_dgemm(double *res, double *a, double *b, int n, int k, int m)
{
}

void print(double *a, int n, int m)
{
	int i, j;
	for (i=0; i<n; ++i)
	{
			for (j=0; j<m; ++j)
					printf("%lf\t", a[i+j*n]);

			printf("\n");
	}
}

double* gen_a(int n, int m)
{
		double *a = (double*)calloc(n*m, sizeof(double));
		int i, j;
		for (i=0; i<n; ++i)
				for (j=0; j<m; ++j)
						a[i+j*n] = i*10 + j;
		return a;
}

double* gen_b(int n, int m)
{
		double *b = (double*)calloc(n*m, sizeof(double));
		int i, j;
		for (i=0; i<n; ++i)
				for (j=0; j<m; ++j)
						b[i+j*n] = i*j;
		return b;
}

int main()
{
	const MKL_INT n = 5;
	const MKL_INT k = 8;
	const MKL_INT m = 6;
	const MKL_INT nb = 2;
	const MKL_INT nprow = 2;
	const MKL_INT npcol = 3;

    MKL_INT iam, nprocs, ictxt, myrow, mycol;
    MDESC   descA, descB, descC, descA_local, descB_local, descC_local;
    MKL_INT mp, nq, lld, lld_local;
	MKL_INT info;

    blacs_pinfo_( &iam, &nprocs );
    blacs_get_( &i_negone, &i_zero, &ictxt );
    blacs_gridinit_( &ictxt, "R", &nprow, &npcol );
    blacs_gridinfo_( &ictxt, &nprow, &npcol, &myrow, &mycol );

    double *a = 0;
    double *b = 0;
	double *c = 0;

    if (iam==0)
    {
		a = gen_a(n, k);
		b = gen_b(k, m);
		c = (double*)calloc(n*m, sizeof(double));

		puts("a=");
		print(a, n, k);

		puts("b=");
		print(b, k, m);
    }

    a_mp = numroc_( &n, &nb, &myrow, &i_zero, &nprow );
    a_nq = numroc_( &k, &nb, &mycol, &i_zero, &npcol );

	b_mp = numroc_( &k, &nb, &myrow, &i_zero, &nprow );
	b_nq = numroc_( &m, &nb, &mycol, &i_zero, &npcol );

    c_mp = numroc_( &n, &nb, &myrow, &i_zero, &nprow );
	c_nq = numroc_( &m, &nb, &mycol, &i_zero, &npcol );

    double *A = (double*) calloc( a_mp * a_nq, sizeof( double ) );
    double *B = (double*) calloc( b_mp * b_nq, sizeof( double ) );
    double *C = (double*) calloc( c_mp * c_nq, sizeof( double ) );

    a_lld_local = MAX( numroc_( &n, &k, &myrow, &i_zero, &nprow ), 1 );
    a_lld = MAX( mp, 1 );

    descinit_( descA_local, &n, &n, &n, &n, &i_zero, &i_zero, &ictxt, &lld_local, &info );
    descinit_( descB_local, &n, &n, &n, &n, &i_zero, &i_zero, &ictxt, &lld_local, &info );
    descinit_( descC_local, &n, &n, &n, &n, &i_zero, &i_zero, &ictxt, &lld_local, &info );

    descinit_( descA, &n, &n, &nb, &nb, &i_zero, &i_zero, &ictxt, &lld, &info );
    descinit_( descB, &n, &n, &nb, &nb, &i_zero, &i_zero, &ictxt, &lld, &info );
    descinit_( descC, &n, &n, &nb, &nb, &i_zero, &i_zero, &ictxt, &lld, &info );

//    pdgeadd_( &trans, &n, &n, &one, a, &i_one, &i_one, descA_local, &zero, A, &i_one, &i_one, descA );
//    pdgeadd_( &trans, &n, &n, &one, b, &i_one, &i_one, descB_local, &zero, B, &i_one, &i_one, descB );

    pdgemm_( "N", "N", &n, &n, &n, &one, A, &i_one, &i_one, descA, B, &i_one, &i_one, descB,
             &zero, C, &i_one, &i_one, descC );

//	pdgeadd_( &trans, &n, &n, &one, C, &i_one, &i_one, descC, &zero, c, &i_one, &i_one, descC_local);

	if (iam==0)
	{
			puts("a");
			print(A, nq, mp);
			puts("b");
			print(B, nq, mp);
			puts("c");
			print(C, nq, mp);
			puts("global c");
			print(c, n, n);
	}

	free(A);
	free(B);
	free(C);
	if (iam==0)
	{
			free(a);
			free(b);
			free(c);
	}

    blacs_gridexit_( &ictxt );
    blacs_exit_( &i_zero );
}
