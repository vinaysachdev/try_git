#include <iostream>

enum level  {quarter=1, dime, cent, penny};

int findChange(int dollarsLeft, level l) {
	//std::cout<<dollarsLeft<<" "<<l<<std::endl;
	if(dollarsLeft < 0) return 0;
	if(dollarsLeft == 0) return 1;
	int noOfwaysToChange = 0;
	switch(l) {
		case quarter: noOfwaysToChange += findChange(dollarsLeft - 25, quarter);
		case dime: noOfwaysToChange += findChange(dollarsLeft - 10, dime);
		case cent: noOfwaysToChange += findChange(dollarsLeft - 5, cent);
		case penny: noOfwaysToChange += findChange(dollarsLeft - 1, penny);
		default: break;
	}
	return noOfwaysToChange;
}

int main() {
	int cents = 25;
	std::cout<< "no of ways to change "<< cents << " cents is: "<< findChange(cents, quarter) << std::endl;
	return 0;
}
