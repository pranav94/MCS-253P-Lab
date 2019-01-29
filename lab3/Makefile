CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: urlParse.cpp countChars.cpp
	echo -------Compiling urlParse.cpp to create executable urlParse---------
	g++ -ggdb $(CXXFLAGS) urlParse.cpp -o urlParse
	echo -------Compiling countChars.cpp to create executable countChars---------
	g++ -ggdb $(CXXFLAGS) countChars.cpp -o countChars
	echo -------Compiling romanToInteger.cpp to create executable romanToInteger---------
	g++ -ggdb $(CXXFLAGS) romanToInteger.cpp -o romanToInteger

clean:
	echo -------Removing executable program urlParse----------
	/bin/rm urlParse
	echo -------Removing executable program countChars----------
	/bin/rm countChars
	echo -------Removing executable program romanToInteger----------
	/bin/rm romanToInteger
