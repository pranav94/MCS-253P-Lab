CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: parseCmd.cpp testIntegers.cpp
	echo -------Compiling parseCmd.cpp to create executable parseCmd---------
	g++ -ggdb $(CXXFLAGS) parseCmd.cpp -o parseCmd
	echo -------Compiling testIntegers.cpp to create executable testIntegers---------
	g++ -ggdb $(CXXFLAGS) testIntegers.cpp -o testIntegers

clean:
	echo -------Removing executable program parseCmd----------
	/bin/rm parseCmd
	echo -------Removing executable program testIntegers----------
	/bin/rm testIntegers
