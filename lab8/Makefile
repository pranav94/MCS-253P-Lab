CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: closest_product.cpp
	echo -------Compiling closest_product.cpp to create executable closest_product---------
	g++ -ggdb $(CXXFLAGS) closest_product.cpp -o closest_product

clean:
	echo -------Removing executable program closest_product----------
	/bin/rm closest_product
