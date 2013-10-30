#include <iostream>
#include "linklist.hh"

using namespace std;

void insert(node** l, int data) {
	node* p = new node(data);
	p->next = *l;
	*l = p;	
}

void deleteNode(node** list, int data) {
	if(*list == NULL) return;
	// first element to be deleted 
	if((*list)->data == data) {
		node *tmp = (*list);
		*list = (*list)->next;
		delete(tmp);
		return;
	}
	node * prev = *list;
	node * curr = (*list)->next;
	while(curr != NULL && curr->data != data) {
		prev = curr;
		curr = curr->next;
	}
	if(curr != NULL) {
		prev->next = curr->next;
		delete(curr);
	}
	return;
}

void printList(node* list) {
	while(list != NULL) {
		cout << list->data << "->";
		list = list->next;
	}
	cout << "NULL"<<std::endl;
}

void removeDuplicates(node* list) {
	if(list == NULL) return;
	node * prev = list;
	node * curr = (list)->next;
	while(curr != NULL) {
		node * moving = list;
		while(curr != NULL && moving != curr) {
			if(moving->data == curr->data) {
				node * tmp = curr;
				prev->next = curr->next;
				curr = curr->next;
				delete(tmp);
			}
			moving = moving->next;
		}
		if(curr != NULL) {
			prev = curr;
			curr = curr->next;
		}
	}
}

node * nthFromLast(node* list, int indx) {
	if(list == NULL) return NULL;
	node * forward = list;
	node * behind = list;
	while(indx >= 0 && forward != NULL) {
		if(forward == NULL)
		   	return NULL;
		forward = forward->next;
		indx--;
	}
	while(forward != NULL) {
		forward = forward->next;
		behind = behind->next;
	}
	return behind;
}
