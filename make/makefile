VPATH = src tools include
CPPFLAGS = -I include

all: stylecheck plot

plot: plot.o
plot.o: include/consts.h plot.cpp 
stylecheck: tools/config2cpp.cpp
	./cpplint.py $?
	touch $@

include/consts.h: config.txt config2cpp
	./config2cpp config.txt include/consts.h

config2cpp: config2cpp.o
config2cpp.o: config2cpp.cpp

clean:
	-rm stylecheck
	-rm *.o
	-rm plot
	-rm config2cpp

dist-clean: clean
	-rm include/consts.h

include definition.mk
df:
	@$(free-space)
	$(call sum,3,5)

STRINGS = ac bc
test:
	# $(STRINGS:c=d)

.PHONY: \
	clean \
	dist-clean
