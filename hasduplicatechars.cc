#include <iostream>
#include <string>

using namespace std;

bool hasDuplicateChars(string str) {
	if(!str.empty()) {
		int indx = 1;
		while(indx < str.size()) {
			for(int i = 0; i < indx; i++) {
				if(str[indx] == str[i])
					return true;
			}
			indx++;
		}
		return false;
	}
	return true;
}

int main() {
	string s = "";
	if(hasDuplicateChars(s))
		cout <<"String: "<< s << " has Duplicate chars"<< endl;
	else
		cout <<"String: "<< s << " has Unique chars"<< endl;
	return 0;
}
