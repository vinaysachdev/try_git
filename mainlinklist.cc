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
			case 3: cout<<"Enter the data: ";
					cin >> data;
					deleteNode(&list, data);
					break;
			case 4: removeDuplicates(list);
					break;
			case 5: {
						cout<<"Enter the index from end: ";
						cin >> data;
						node* n = nthFromLast(list, data);
						if(n == NULL)
							cout<<"No of nodes in list is less than "<<data<<endl;
						else
							cout << data << " node from last is: "<< n->data<<endl;
					}
					break;
			case 6: list = reverse(list);
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
	cout<<"   Options"<<endl;
	cout<<"   -------"<<endl;
	cout<<"1. Print"<<endl;
	cout<<"2. Insert"<<endl;
	cout<<"3. Delete"<<endl;
	cout<<"4. Remove Duplicates"<<endl;
	cout<<"5. Nth node from last"<<endl;
	cout<<"6. reverse the list"<<endl;
	cout<<"0. Quit"<<endl;
	cout<<"Choose the option( Enter '0' to quit): "<<endl;
}
