#include <iostream>

using namespace std;

void reverseString(char str[]) {
	if(str == NULL) return;
	int len  = strlen(str);
	for(int i=0, j=len-1; i < j; i++, j--) {
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	cout <<"string: "<< str<< endl;
}

int main() {
	char s[256] = "abcd";
	cout << "string before reverse: "<< s <<endl;
	reverseString(s);
	cout << "Reverse string is: " << s << endl;
	return 0;
}
