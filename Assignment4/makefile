all: main #test

.PHONY: all clean

main: main.o complex.o
	g++ -g -Wall -o main main.o complex.o

#test: test.o complex.o
#	g++ -g -Wall -v -o test test.o complex.o

#test.o: test.cpp complex.hpp Node.hpp Tree.hpp doctest.h
#	g++ -g -Wall -c test.cpp -o test.o

#valgrind:
#	valgrind --leak-check=full ./main

complex.o: complex.cpp complex.hpp
	g++ -g -Wall -c complex.cpp

main.o: main.cpp complex.hpp Node.hpp Tree.hpp
	g++ -g -Wall -c main.cpp

clean:
	rm -f main *.o
