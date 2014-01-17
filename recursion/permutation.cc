#include <iostream>
#include <string>

void recPermute(std::string sofar, std::string rest) {
	if(rest.empty())
		std::cout<< sofar << std::endl;
	else {
		for(int i = 0; i < rest.size(); i++) {
			std::string str = rest.substr(0, i) + rest.substr(i+1);
			recPermute(sofar + rest[i], str);
		}
	}
}

int main() {
	recPermute("", "1234");
	return 0;
}
