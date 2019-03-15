CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: next_permutation.cpp SpiralMatrix.cpp
	echo -------Compiling next_permutation.cpp to create executable next_permutation---------
	g++ -ggdb $(CXXFLAGS) next_permutation.cpp -o next_permutation
	echo -------Compiling SpiralMatrix.cpp to create executable SpiralMatrix---------
	g++ -ggdb $(CXXFLAGS) SpiralMatrix.cpp -o SpiralMatrix

clean:
	echo -------Removing executable program next_permutation----------
	/bin/rm next_permutation
	echo -------Removing executable program SpiralMatrix----------
	/bin/rm SpiralMatrix
