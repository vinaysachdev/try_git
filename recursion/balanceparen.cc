#include <iostream>
#include <string>

// this algorithm works using backtracking.
void balanceParen(std::string parenStr, int noOfLeftParen, int noOfRightParen, int n) {
	if(noOfLeftParen == noOfRightParen && noOfRightParen == n) {
		std::cout << parenStr << std::endl;
	}
	else {
		if(noOfLeftParen > noOfRightParen) {
			balanceParen(parenStr + ")", noOfLeftParen, noOfRightParen + 1, n);
		} 
		if(noOfLeftParen < n) {
			balanceParen(parenStr + "(", noOfLeftParen + 1, noOfRightParen, n);
		}
	}
}

int main() {
	balanceParen("", 0, 0, 2);
	return 0;
}
