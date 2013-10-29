#include <iostream>
#include "linklist.hh"

using namespace std;

void insert(node** l, int data) {
	node* p = new node(data);
	p->next = *l;
	*l = p;	
}

void printList(node* list) {
	while(list != NULL) {
		cout << list->data << "->";
		list = list->next;
	}
	cout << "NULL"<<std::endl;
}
