#include <iostream>
#include <string>
#include <vector>

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


bool isUniqueChars(string s) {
	vector<bool> chars(256, false);
	for(int i = 0; i < s.size(); i++) {
		int c = s[i];
		if(chars[c] == true) return false;
		chars[c] = true;
	}
	return true;
}

int main() {
	string s = "abcd";
	//if(hasDuplicateChars(s))
	if(!isUniqueChars(s))
		cout <<"String: "<< s << " has Duplicate chars"<< endl;
	else
		cout <<"String: "<< s << " has Unique chars"<< endl;
	return 0;
}
