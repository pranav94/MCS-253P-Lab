CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: dna.cpp levenshtein.cpp
	echo -------Compiling dna.cpp to create executable dna---------
	g++ -ggdb $(CXXFLAGS) dna.cpp -o dna
	echo -------Compiling levenshtein.cpp to create executable levenshtein---------
	g++ -ggdb $(CXXFLAGS) levenshtein.cpp -o levenshtein


clean:
	echo -------Removing executable program dna----------
	/bin/rm dna
	echo -------Removing executable program levenshtein----------
	/bin/rm levenshtein
