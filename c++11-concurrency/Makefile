BINS=threads mutex atomic future serial boost_atomic condition_variable thread_lambda singleton

all: $(BINS)

SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp,%.o,$(SOURCES))

CC=g++
LD=g++
CPPFLAGS=-std=c++11 -Wall -g -O2 -m64
LDFLAGS=-pthread -m64

%: %.o
	$(LD) $^ -o $@ $(LDFLAGS) 

.PHONY: clean
clean:
	-rm *.o
	-rm $(BINS)
