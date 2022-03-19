INCS = shelpers.hpp

OBJS = main.o shelpers.o

shell: $(OBJS)
	c++ --std=c++14 -O2 -o shell $(OBJS)

main.o : main.cpp $(INCS)
	c++ --std=c++14 -O2 -c main.cpp

shelpers.o : shelpers.cpp $(INCS)
	c++ --std=c++14 -O2 -c shelpers.cpp

clean :
	rm -f $(OBJS)