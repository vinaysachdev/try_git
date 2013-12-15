#include <iostream>
#include <cassert>
#include "tree.hh"

using namespace std;

void testisBalanced();
void testfindLevelLinklist();
void testscuccessor();
void testfindCommonAncestor();
void testisContainTree();

int main() {
	testisBalanced();
	testfindLevelLinklist(); 
	//testscuccessor();
	testfindCommonAncestor();
	testisContainTree();
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

node<int>* createTree() {
	node<int>* tree = NULL; 
	insert(&tree, 8);
	insert(&tree, 10);
	insert(&tree, 6);
	insert(&tree, 9);
	insert(&tree, 11);
	insert(&tree, 5);
	insert(&tree, 7);
	return tree;
}

void testfindLevelLinklist() {
	node<int>* tree = createTree();
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
	node<int>* tree = createTree();
	node<int>* succ = successor(lookup(tree, 9));
	assert(succ->val == 10);
	succ = successor(lookup(tree, 7));
	assert(succ->val == 8);
}

void testfindCommonAncestor() {
	node<int>* tree = createTree();
	node<int>* commonAncestor = findCommonAncestor(tree, lookup(tree, 5), lookup(tree, 10));
	assert(commonAncestor->val == 8);
	cout<<"The common ancestor of 5 and 10 is: "<<commonAncestor->val<<endl;
	commonAncestor = findCommonAncestor(tree, lookup(tree, 5), lookup(tree, 7));
	assert(commonAncestor->val == 6);
	cout<<"The common ancestor of 5 and 7 is: "<<commonAncestor->val<<endl;
}

void testisContainTree() {
	node<int>* tree = createTree();
	assert(isContainTree(tree, lookup(tree, 6)) == true);
	//test for leaf
	assert(isContainTree(tree, lookup(tree, 7)) == true);
	// test for empty tree
	assert(isContainTree((node<int>*)NULL, lookup(tree, 6)) == false);
	//test for empty subtree
	assert(isContainTree(tree, lookup(tree, 70)) == true);
	node<int>* subtree = NULL; 
	insert(&subtree, 20);
	assert(isContainTree(tree, subtree) == true);
}
