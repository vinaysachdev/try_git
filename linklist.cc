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

// start from 2nd element and search backwards if it is a duplicate element
// if yes then remove that element. By searching backwards you are sure that
// previous elements are already removed
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

node * sumLists(node * l1, node * n2) {
	if(l1 == NULL && l2 == NULL) return NULL;
	node * sum  = NULL;
	if(l2 == NULL) {
		sum = sumLists(l1->next, NULL);	
	}
	else if(l1 == NULL) {
		sum = sumList(NULL, l2->next);
	}
	else
		sum = 
}
