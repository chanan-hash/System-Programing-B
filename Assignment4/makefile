#Authors: Chanan helman
#chananhelman@gmail.com


# all: main #test

# .PHONY: all clean

# main: main.o complex.o
# 	g++ -g -Wall -o main main.o complex.o

# #test: test.o complex.o
# #	g++ -g -Wall -v -o test test.o complex.o

# #test.o: test.cpp complex.hpp Node.hpp Tree.hpp doctest.h
# #	g++ -g -Wall -c test.cpp -o test.o

# #valgrind:
# #	valgrind --leak-check=full ./main

# complex.o: complex.cpp complex.hpp
# 	g++ -g -Wall -c complex.cpp

# main.o: main.cpp complex.hpp Node.hpp Tree.hpp
# 	g++ -g -Wall -c main.cpp

# clean:
# 	rm -f main *.o
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -I/usr/include/SFML

# Linker flags
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = main.cpp complex.cpp

# Header files
HEADERS = Tree.hpp Node.hpp complex.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = tree_visualization

# Default target
all: $(EXEC)

# Link the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean