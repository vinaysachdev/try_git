
typedef struct node {
	node(int d):data(d), next(NULL) { }
	int data;
	node* next;
} node;

void insert(node** l, int data);
void deleteNode(node** l, int data);
void printList(node* l);
void removeDuplicates(node* list);
node * nthFromLast(node* list, int indx);
