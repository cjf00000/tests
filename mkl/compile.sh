 mpicc -w -o pdgemv pdgemv.c -I/home/jianfei/bin/intel/composer_xe/mkl/include -L/home/jianfei/bin/intel/composer_xe/mkl/lib/intel64 -I/usr/include  -lmkl_scalapack_lp64 -lmkl_blacs_intelmpi_lp64 -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_core -lpthread -liomp5 -ldl -lm -L/home/jianfei/bin/intel/composer_xe/composer_xe_2013.2.146/compiler/lib/intel64

