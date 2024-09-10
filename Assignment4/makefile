#Authors: Chanan helman
#chananhelman@gmail.com
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -g -Wall -Wextra -Werror

# Linker flags
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

TEST_SRC = Tree.hpp TestCounter.cpp complex.cpp test.cpp Node.hpp

SRC = main.cpp Tree.hpp complex.cpp Node.hpp

# Phony targets
.PHONY: all clean

tree: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o tree $(LDFLAGS)
	./tree

test: test.o complex.o TestCounter.o
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o test $(LDFLAGS)
	./test

valgrind: tree test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./tree 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

tidy:
	clang-tidy $(SRC) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f *.o test valgrind tree