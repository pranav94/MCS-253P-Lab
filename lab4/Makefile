CXXFLAGS=-std=c++11
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: product.cpp polish.cpp
	echo -------Compiling product.cpp to create executable product---------
	g++ -ggdb $(CXXFLAGS) product.cpp -o product
	echo -------Compiling polish.cpp to create executable polish---------
	g++ -ggdb $(CXXFLAGS) polish.cpp -o polish
	echo -------Compiling process_numbers.cpp to create executable process_numbers.cpp---------
	g++ -ggdb $(CXXFLAGS) process_numbers.cpp -o process_numbers
	echo -------Compiling mapset.cpp to create executable mapset.cpp---------
	g++ -ggdb $(CXXFLAGS) mapset.cpp -o mapset


clean:
	echo -------Removing executable program product----------
	/bin/rm product
	echo -------Removing executable program polish----------
	/bin/rm polish
	echo -------Removing executable program process_numbers----------
	/bin/rm process_numbers
	echo -------Removing executable program mapset----------
	/bin/rm mapset
