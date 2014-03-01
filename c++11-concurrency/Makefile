BINS=threads mutex atomic future serial boost_atomic condition_variable producer_consumer

all: $(BINS)

SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp,%.o,$(SOURCES))

CC=g++
LD=g++
CPPFLAGS=-std=c++11 -Wall -g -O2
LDFLAGS=-pthread

%: %.o
	$(LD) $^ -o $@ $(LDFLAGS) 

.PHONY: clean
clean:
	-rm *.o
	-rm $(BINS)
