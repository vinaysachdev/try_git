#include <iostream>
#include <stack>

using namespace std;

void sortBystack(stack<int>& inputStack, stack<int>& outputStack);

int main() {
	stack<int> inputStack, outputStack;
	inputStack.push(2);
	inputStack.push(8);
	inputStack.push(7);
	inputStack.push(3);
	inputStack.push(9);
	inputStack.push(1);
	sortBystack(inputStack, outputStack);
	while(!outputStack.empty()) {
		cout<<outputStack.top()<< " ";
		outputStack.pop();
	}
	cout<<endl;
	return 0;
}

void sortBystack(stack<int>& inputStack, stack<int>& outputStack) {
	while(! inputStack.empty()) {
		int tmp = inputStack.top();
		inputStack.pop();
		while(! outputStack.empty() && tmp < outputStack.top()) {
			inputStack.push(outputStack.top());
			outputStack.pop();
		}
		outputStack.push(tmp);
	}
}
