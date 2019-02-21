CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: dijsktras.cpp mst.cpp
	echo -------Compiling dijsktras.cpp to create executable dijsktras---------
	g++ -ggdb $(CXXFLAGS) dijsktras.cpp -o dijsktras
	echo -------Compiling mst.cpp to create executable MST---------
	g++ -ggdb $(CXXFLAGS) mst.cpp -o mst


clean:
	echo -------Removing executable program dijsktras----------
	/bin/rm dijsktras
	echo -------Removing executable program mst----------
	/bin/rm mst
