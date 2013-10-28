#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isAnagrams(string s1, string s2) {
	int s1_size = s1.size();
	int s2_size = s2.size();

	if(s1_size != s2_size) return false;
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	return s1 == s2;
}

int main() {
	string s1 = "abcd";
	string s2 = "cad";
	if(isAnagrams(s1, s2))
		cout << s1 << " and "<< s2 <<" are anagrams."<<endl;
	else
		cout << s1 << " and "<< s2 <<" are NOT anagrams."<<endl;
	return 0;
}
