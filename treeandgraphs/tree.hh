#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
enum NODES_FOUND {NONE, ONE, TWO};

template <typename T>
struct node {
	T val;
	node* left;
	node* right;
	node* parent;

	node(T v, node* l, node* r, node* p=NULL):
			val(v), left(l), right(r), parent(p) {}
};
template <typename T>
void insert(node<T>** tree, T val) {
	if(*tree == NULL) {
		node<T>* newNode = new node<T>(val, NULL, NULL);
		*tree = newNode;
	}else if((*tree)->val > val)
		insert(&((*tree)->left), val);
	else
		insert(&((*tree)->right), val);
}

template <typename T>
int maxDepth(node<T>* tree) {
	if(tree == NULL) return 0;
	return 1 + std::max(maxDepth(tree->left), maxDepth(tree->right));
}

template <typename T>
int minDepth(node<T>* tree) {
	if(tree == NULL) return 0;
	return 1 + std::min(minDepth(tree->left), minDepth(tree->right));
}

template <typename T>
bool isBalanced(node<T>* tree) {
	return (maxDepth(tree) - minDepth(tree) <= 1);
}

template <typename T>
node<T>* arrayToBinaryTree(T a[], int low, int high) {
	if(low > high) return NULL;

	int middle = low + (high - low)/2;
	node<T>* tree = new node<T>(a[middle], NULL, NULL);
	tree->left = arrayToBinaryTree(a, low, middle-1);
	tree->right = arrayToBinaryTree(a, middle+1, high);
	
	return tree; 
}

// we are using Depth First Search for traversing each level
// and creating linklisk of nodes at each level. Delimiter for
// each level is NULL pointer.
template <typename T>
vector<node<T>*> findLevelLinklist(node<T>* tree) {
	vector<node<T>*> vecList;
	if(tree == NULL) return vecList;
	queue<node<T>*> q;
	q.push(tree);
	q.push(NULL);
	while(! q.empty()) {
		node<T>* tmp = q.front();
		q.pop();
		node<T>* n = new node<T>(tmp->val, NULL, NULL);
		vecList.push_back(n);
		if(tmp->left != NULL) q.push(tmp->left);
		if(tmp->right != NULL) q.push(tmp->right);
		while(q.front() != NULL) {
			tmp = q.front();
			q.pop();
			n->left = new node<T>(tmp->val, NULL, NULL);
			n = n->left;
			if(tmp->left != NULL) q.push(tmp->left);
			if(tmp->right != NULL) q.push(tmp->right);
		}
		q.pop();
		if(!q.empty())
			q.push(NULL);
	}
	return vecList;
}	

template <typename T>
node<T>* leftMostChild(node<T> * n) {
	if(n == NULL) return NULL;
	while(n->left != NULL)
		n = n->left;
	return n; 
}

//finds the immediate successor of a given node
template <typename T>
node<T>* successor(node<T>* tree) {
	if(tree == NULL) return NULL;
	if(tree->parent == NULL || tree->right != NULL)
		return leftMostChild(tree->right);
	else {
		while(tree->parent != NULL) {
			if(tree->parent->right == tree)
				tree = tree->parent;
			else
				return tree->parent;
		}
		return tree;
		}
}

template <typename T>
node<T>* lookup(node<T>* tree, T val) {
	if(tree == NULL) return NULL;
	if(val == tree->val)
		return tree;
	if(val < tree->val)
		return lookup(tree->left, val);
	else
		return lookup(tree->right, val);
}

template <typename T>
int covers(node<T>* root, node<T>* p, node<T>* q) {
	int ret = NONE;
	if( root == NULL) return ret;
	if(root == p || root == q) return ret + 1;

	ret += covers(root->left, p, q);
	if(ret == TWO)
		return ret;
	return ret + covers(root->right, p, q);
}

template <typename T>
node<T>* findCommonAncestor(node<T>* root, node<T>* p, node<T>* q) {
	if( p == q && (root->left == q || root->right == q))
		return root;
	int nodesFoundFromLeft = covers(root->left, p, q);
	if(nodesFoundFromLeft == TWO) {
		if(root->left == p || root->left == q)
			return root->left;
		return findCommonAncestor(root->left, p, q);
	}else if(nodesFoundFromLeft == ONE) {
		if(root == p) return p;
		if(root == q) return q;
	}

	int nodesFoundFromRight = covers(root->right, p, q);
	if(nodesFoundFromRight == TWO) {
		if(root->right == p || root->right == q)
			return root->right;
		return findCommonAncestor(root->right, p, q);
	} else if(nodesFoundFromRight == ONE) {
			if(root == p) return p;
			if(root == q) return q;
	}
	if(nodesFoundFromLeft == ONE && nodesFoundFromRight == ONE)
		return root;
	return NULL;
}

// checks whether t2 is subtree of t1
template <typename T>
bool isContainTree(node<T>* t1, node<T>* t2) {
	if(t2 == NULL) return true;
	return isSubtree(t1, t2);
}

template <typename T>
bool isSubtree(node<T>* t1, node<T>* t2) {
	if(t1 == NULL && t2 == NULL) return true;
	if(t1 == NULL) return false;
	if(t2 == NULL) return true;

	if(t1->val == t2->val) {
		if(isSubtree(t1->left, t2->left) && isSubtree(t1->right, t2->right))
			return true;
	}
	return isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
}

template <typename T>
void printPath(vector<T> v, int start, int end) {
	for(int i = start; i <= end; i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

// print all paths which add upto "sum". The path need not necessarily
// start from root, it can start from anywhere.
template <typename T>
void printAllPathsToSum(node<T>* tree, int sum, vector<T> vecNum, int level) {
	if(tree == NULL) return;
	T tmp = sum;
	vecNum.push_back(tree->val);

	for(int i=level; i <= 0; i--) {
		tmp -= vecNum[i];
		if(tmp == 0)
			printPath(vecNum, i, level);
	}

	vector<T> v1 = vecNum;
	vector<T> v2 = vecNum;
	printAllPathsToSum(tree->left, sum, v1, level+1);
	printAllPathsToSum(tree->right, sum, v2, level+1);
}

