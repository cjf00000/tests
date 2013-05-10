example:
	g++ -c example.cpp -o example.o -m64 -I$(MKLROOT)/include -I/home/jianfei/bin/include 
	g++ example.o -o example -L$(MKLROOT)/lib/intel64 -L$(ICCROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -lm -L/home/jianfei/bin/lib -larmadillo
