CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: next_permutation.cpp SpiralMatrix.cpp BinaryTree.cpp SegregateColors.cpp LargestSubarraySum.cpp RotatedArray.cpp
	@echo -------Compiling next_permutation.cpp to create executable next_permutation---------
	@g++ -ggdb $(CXXFLAGS) next_permutation.cpp -o next_permutation
	@echo -------Compiling SpiralMatrix.cpp to create executable SpiralMatrix---------
	@g++ -ggdb $(CXXFLAGS) SpiralMatrix.cpp -o SpiralMatrix
	@echo -------Compiling BinaryTree.cpp to create executable BinaryTree---------
	@g++ -ggdb $(CXXFLAGS) BinaryTree.cpp -o BinaryTree
	@echo -------Compiling SegregateColors.cpp to create executable SegregateColors---------
	@g++ -ggdb $(CXXFLAGS) SegregateColors.cpp -o SegregateColors
	@echo -------Compiling LargestSubarraySum.cpp to create executable LargestSubarraySum---------
	@g++ -ggdb $(CXXFLAGS) LargestSubarraySum.cpp -o LargestSubarraySum
	@echo -------Compiling RotatedArray.cpp to create executable RotatedArray---------
	@g++ -ggdb $(CXXFLAGS) RotatedArray.cpp -o RotatedArray

clean:
	@echo -------Removing executable program next_permutation----------
	@/bin/rm next_permutation
	@echo -------Removing executable program SpiralMatrix----------
	@/bin/rm SpiralMatrix
	@echo -------Removing executable program BinaryTree----------
	@/bin/rm BinaryTree
	@echo -------Removing executable program SegregateColors----------
	@/bin/rm SegregateColors
	@echo -------Removing executable program LargestSubarraySum----------
	@/bin/rm LargestSubarraySum
	@echo -------Removing executable program RotatedArray----------
	@/bin/rm RotatedArray
