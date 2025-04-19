# Author: realyoavperetz@gmail.com

.PHONY: Main test valgrind clean
# Compile and run the main program
Main: main.cpp source/SquareMatrix.cpp
	g++ -o Main main.cpp source/SquareMatrix.cpp -Iinclude
	./Main
# Compile and run tests
test: tests/tests.cpp source/SquareMatrix.cpp
	g++ -o test tests/tests.cpp source/SquareMatrix.cpp -Iinclude
	./test

# Check for memory leaks using valgrind
valgrind: Main
	valgrind --leak-check=full ./Main

# Clean up build files
clean:
	rm -f Main test 