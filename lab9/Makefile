CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: next_permutation.cpp
	echo -------Compiling next_permutation.cpp to create executable next_permutation---------
	g++ -ggdb $(CXXFLAGS) next_permutation.cpp -o next_permutation

clean:
	echo -------Removing executable program next_permutation----------
	/bin/rm next_permutation
