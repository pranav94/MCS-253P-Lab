CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: dna.cpp
	echo -------Compiling dna.cpp to create executable dna---------
	g++ -ggdb $(CXXFLAGS) dna.cpp -o dna


clean:
	echo -------Removing executable program dna----------
	/bin/rm dna
