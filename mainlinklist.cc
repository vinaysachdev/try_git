#include <iostream>
#include "linklist.hh"

using namespace std;

void printChoice();

int main() {
	int choice;
	node* list = NULL;
	int data;
	bool isQuit = false;
	while(true) {
		printChoice();
		cin >> choice;
		switch(choice) {
			case 1: printList(list);
					break;
			case 2: cout<<"Enter the data: ";
					cin >> data;
					insert(&list, data);
					break;
			case 0: isQuit = true;
					break;
			default: isQuit = true; 
					 break;
		}
		if(isQuit) break;
	}
	return 0;
}

void printChoice() {
	cout<<"1. Print"<<endl;
	cout<<"2. Insert"<<endl;
	cout<<"0. Quit"<<endl;
	cout<<"Choose the option( Enter '0' to quit): "<<endl;
}
