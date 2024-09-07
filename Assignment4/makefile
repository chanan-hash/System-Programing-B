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

# Phony targets
.PHONY: all clean


valgrind: $(DEMO) $(TEST_SRC)
#	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

test: test.o complex.o TestCounter.o
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o test $(LDFLAGS)
	./test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f *.o test valgrind