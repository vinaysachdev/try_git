#include <iostream>
#include <cassert>
#include "tree.hh"

using namespace std;

void testisBalanced();
void testfindLevelLinklist();
void testscuccessor();
void testfindCommonAncestor();

int main() {
	testisBalanced();
	testfindLevelLinklist(); 
	//testscuccessor();
	testfindCommonAncestor();
	return 0;
}

void testisBalanced() {
	node<int>* tree = NULL; 
	insert(&tree, 8);
	insert(&tree, 10);
	insert(&tree, 6);
	insert(&tree, 9);
	cout<<"root val: "<<tree->val<<std::endl;
	cout<<"is balanced: "<<isBalanced(tree)<<endl;
	insert(&tree, 5);
	insert(&tree, 4);
	cout<<"is balanced: "<<isBalanced(tree)<<endl;
}

void testfindLevelLinklist() {
	node<int>* tree = NULL; 
	insert(&tree, 8);
	insert(&tree, 10);
	insert(&tree, 6);
	insert(&tree, 9);
	insert(&tree, 11);
	insert(&tree, 5);
	insert(&tree, 7);
	vector<node<int>*> vecList = findLevelLinklist(tree);
	for(auto n:vecList) {
		while(n!=NULL) {
			cout<<n->val<<"->";
			n = n->left;
		}
		cout<<"NULL"<<endl;
	}
}

void testscuccessor() {
	node<int>* tree = NULL; 
	insert(&tree, 8);
	insert(&tree, 10);
	insert(&tree, 6);
	insert(&tree, 9);
	insert(&tree, 11);
	insert(&tree, 5);
	insert(&tree, 7);
	node<int>* succ = successor(lookup(tree, 9));
	assert(succ->val == 10);
	succ = successor(lookup(tree, 7));
	assert(succ->val == 8);
}

void testfindCommonAncestor() {
	node<int>* tree = NULL; 
	insert(&tree, 8);
	insert(&tree, 10);
	insert(&tree, 6);
	insert(&tree, 9);
	insert(&tree, 11);
	insert(&tree, 5);
	insert(&tree, 7);
	node<int>* commonAncestor = findCommonAncestor(tree, lookup(tree, 5), lookup(tree, 10));
	assert(commonAncestor->val == 8);
	cout<<"The common ancestor of 5 and 10 is: "<<commonAncestor->val<<endl;
	commonAncestor = findCommonAncestor(tree, lookup(tree, 5), lookup(tree, 7));
	assert(commonAncestor->val == 6);
	cout<<"The common ancestor of 5 and 7 is: "<<commonAncestor->val<<endl;
}

