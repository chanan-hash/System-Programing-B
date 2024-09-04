all: main


main: main.o complex.o
	g++ -g -Wall -o main main.o complex.o


complex.o: complex.cpp complex.hpp
	g++ -g -Wall -c complex.cpp

main.o: main.cpp complex.hpp Node.hpp Tree.hpp
	g++ -g -Wall -c main.cpp

clean:
	rm -f main *.o
