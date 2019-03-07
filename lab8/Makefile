CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: closest_product.cpp count_k_distinct.cpp
	echo -------Compiling closest_product.cpp to create executable closest_product---------
	g++ -ggdb $(CXXFLAGS) closest_product.cpp -o closest_product
	echo -------Compiling make_average.cpp to create executable make_average---------
	g++ -ggdb $(CXXFLAGS) make_average.cpp -o make_average
	echo -------Compiling count_k_distinct.cpp to create executable count_k_distinct---------
	g++ -ggdb $(CXXFLAGS) count_k_distinct.cpp -o count_k_distinct

clean:
	echo -------Removing executable program closest_product----------
	/bin/rm closest_product
	echo -------Removing executable program make_average----------
	/bin/rm make_average
	echo -------Removing executable program count_k_distinct----------
	/bin/rm count_k_distinct
