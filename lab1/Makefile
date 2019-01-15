CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: average.cpp
	echo -------Compiling average.cpp to create executable average---------
	g++ -ggdb $(CXXFLAGS) average.cpp -o average

clean:
	echo -------Removing executable program average----------
	/bin/rm average
