#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "bitmanipulation.hh"

using namespace std;

string stringToBinary(string str) {
	if(str.empty()) return "";
	string int_str = "";
	double num = atof(str.c_str());
	int int_part = num;
	double frac_part = num - int_part; 	

	while(int_part != 0) {
		int_str.append(to_string(int_part%2));
		int_part /= 2;
	}

	string frac_str = "";
	while(frac_part > 0) {
		if(frac_str.size() > 32) return "ERROR";
		if(frac_part == 1) {
			frac_str.push_back('1');
			break;
		}
		double d = frac_part*2;
		if(d >= 1) {
			frac_str.push_back('1');
			frac_part = d - 1.0;
		} else {
			frac_str.push_back('0');
			frac_part = d;
		}
	}
	return int_str + '.' + frac_str;
}

bool getBit(int n, int index) {
	return ((n & (1 << index)) > 0);
}

int setBit(int n, int index, bool b) {
	if(b) {
		return n | (1 << index);
	} else {
		return (n & (~(1 << index)));
	}
}

// get next number with same number of 1 bits set as in n
int getNext_NP(int n) {
	if(n <= 0) return -1;

	int index = 0;
	int noOfOnes = 0;
	//pass 0's from right to left
	while(!getBit(n, index))
		++index;

	// pass 1's from left to right
	while(getBit(n, index)) {
		++index;
		++noOfOnes;
	}
	n = setBit(n, index, true);
	
	--index;
	n = setBit(n, index, false);
	--noOfOnes;
	
	// set zeores
	for(int i = index-1; i >= noOfOnes; i--) {
		n = setBit(n, i, false);
	}

	cout<<"I am here\n";	
	// set ones
	for(int i = noOfOnes-1; i >= 0 ; i--) {
		n = setBit(n, i, true);
	}
	return n;
}

// number of bits required to swap to convert from 'n' to 'm'
int bitSwapRequired(int n, int m) {
	int c = n ^ m;
	int count = 0;
	while(c != 0) {
		count += (c & 1);
		c = c >> 1;
	}
	return count;
}

// mask odd bits with 10101010 in binary (i.e. 0xaa) and shift them right to put them in even bits.
// Then do similar operation for odd bits.
int swapOddEvenBit(int n) {
	return (((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1));
}

int main() {
	string str = ".625";
	cout<<"Binary representation of: "<<str<<" is: "<<stringToBinary(str)<<endl;
	str = "3.625";
	cout<<"Binary representation of: "<<str<<" is: "<<stringToBinary(str)<<endl;
	int n = 15;
	cout<<"The next number greater than "<< n << " with same no of 1\'s is "<<getNext_NP(n)<<endl;
	n = 9;
	int m = 6;
	cout<<"No of bits required to swap to convert "<<n<<" to "<<m<<" is: "<<bitSwapRequired(n, m)<<endl;
	return 0;
}

