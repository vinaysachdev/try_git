#include <vector>
#include <deque>

template <typename T>
class MyStack {
	deque<T> deq;
public:
	void push(T val) {
		deq.push_back(val);
	}

	void pop() {
		deq.pop_back();
	}	

	T removeBottom() {
		T val = deq.front();
		deq.pop_front();
	}
	
	bool empty() {
		return deq.empty();
	}

	T top() {
		return deq.back();
	}
	
	int size() {
		return deq.size();
	}
};

template<typename T>
class StackOfStacks {
	const int MAX_SIZE;
	vector<MyStack<T>> vecStacks;
public:
	StackOfStacks(int size) : MAX_SIZE(size) {
		MyStack<T> newStack;
		vecStacks.push_back(newStack);	
	}

	// presondition size of vector is atleast 1
	void push(T val) {
		int noOfStacks = vecStacks.size();
		if(vecStacks[noOfStacks].size() == MAX_SIZE) {
			MyStack<T> newStack;
			newStack.push(val);
			vecStacks.push_back(newStack);
		} else {
			vecStacks[noOfStacks].push(val);
		}
	}
	//precondition:
	// size of vector is atleast 1
	// container is not empty otherwise the behavior is undefined
	void pop() {
		int noOfStacks = vecStacks.size();
		vecStacks[noOfStacks].pop();
		//vector has atleast one stack even if it is empty
		if(noOfStacks > 1 && vecStacks[noOfStacks].size() == 0)
			vecStacks.pop_back();
	}

	T popAt(int i) {
		return leftShift(i, true);
	}

	// this is little tricky. If we remove an element from an arbitrary stack
	// we have to remove the bottom element from stack in right postion and if
	// right stack it not the last stack we have to do the same thing for it
	// precondition:
	// 	'i' is refering to valid index
	T leftShift(int i, bool removeTop) {
		T element;
		if(removeTop) {
			element = vecStacks[i].top();
			vecStacks[i].pop();
		}
		else
			element = vecStacks[i].removeBottom();
		if(vecStacks[i].empty())
			vecStacks.pop_back();
		if(vecStacks.size() > i+1) {
			T val = leftShift(i+1, false);
			vecStacks[i].push(val);
		}
		return element;
	}

	//precondition:
	// container is not empty otherwise the behavior is undefined
	T top() {
		int noOfStacks = vecStacks.size();
		vecStacks[noOfStacks].top();
	}

	bool empty() {
		int noOfStacks = vecStacks.size();
		return (noOfStacks == 1 && vecStacks[noOfStacks].size() == 0);
	}
};


