#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void replaceSpace(char * s1, int len) {
	int noOfSpace = count(s1, s1 + len, ' ');
	int newLength = len + noOfSpace*2;
	s1[newLength] = '\0';
	for(int i = len - 1; i >= 0; i--) {
		if(s1[i] == ' ') {
			s1[newLength - 3] = '%'; 
			s1[newLength - 2] = '2';
			s1[newLength - 1] = '0';	
			newLength -= 3;
		}
		else {
			s1[newLength - 1] = s1[i];
			newLength -= 1;
		}
	}
}

int main() {
	char str[256] = "I am  vinay";
	cout << "String BEFORE replacement: "<<str<<endl;
	replaceSpace(str, strlen(str));
	cout << "String AFTER replacement: "<<str<<endl;
	return 0;
}
