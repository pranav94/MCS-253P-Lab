CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: next_permutation.cpp BinaryTree.cpp
	echo -------Compiling BinaryTree.cpp to create executable BinaryTree---------
	g++ -ggdb $(CXXFLAGS) BinaryTree.cpp -o BinaryTree

clean:
	echo -------Removing executable program next_permutation----------
	/bin/rm next_permutation
	echo -------Removing executable program BinaryTree----------
	/bin/rm BinaryTree
