#include <iostream>
#include <string>
#include <vector>

using namespace std;

//assuming size of int is 32 bits. 8*32 = 256, no of ascii characters
void removeDuplicates(char* str) {
	vector<int> bitvector(8, 0);
	size_t len = strlen(str);
	if(len == 0) return;

	int c = str[0];
	int i = 1, j = 1; // j is moving index
	// expression inside [] operator calculates where to set the bit for the character 'c'
	bitvector[(c/8) * sizeof(int)] |= (1 << c);
	while(j < len) {
		c = str[j];
		// check if character is already there, if yes skip the character
		if( (1 << c) & bitvector[(c/8) * sizeof(int)] )
			j++;
		else {
			bitvector[(c/8)*sizeof(int)] |= (1 << c);
			str[i] = str[j];
			i++; j++;
		}
	}
	str[i] = '\0';
}

int main() {
	char str[] = "abcdd";
	cout <<"Before removing duplicates: "<<str<<endl;
	removeDuplicates(str);
	cout <<"After removing duplicates: "<<str<<endl;
	return 0;
}
