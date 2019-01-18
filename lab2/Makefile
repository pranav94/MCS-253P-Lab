CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: parseCmd.cpp
	echo -------Compiling parseCmd.cpp to create executable parseCmd---------
	g++ -ggdb $(CXXFLAGS) parseCmd.cpp -o parseCmd

clean:
	echo -------Removing executable program parseCmd----------
	/bin/rm parseCmd
