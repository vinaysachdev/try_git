#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class StackNode {
public:
	T value;
	int previous;
	StackNode(int p, T v):previous(p), value(v) {}
};

template<typename T>
class ThreeStacksUB {
	int indexUsed;
	int stackSize;
	vector<StackNode<T>> buffer;
	int stackPtr[3] = {-1, -1, -1};
public:
	ThreeStacksUB():indexUsed(0), stackSize(3) {
		buffer.reserve(stackSize*3);
	}

	void push(int stackNum, T val) {
		int lastIndexUsed = stackPtr[stackNum];
		stackPtr[stackNum] = indexUsed;
		indexUsed++;
		StackNode<T> stackNode(lastIndexUsed, val);
		buffer[stackPtr[stackNum]] = stackNode; 
	}

	T pop(int stackNum) {
		T val = buffer[stackPtr[stackNum]].value;
		int lastIndex = buffer[stackPtr[stackNum]].previous;
		stackPtr[stackNum] = lastIndex;
		//buffer[indexUsed] = NULL;
		indexUsed--;
		return val;
	}

	T top(int stackNum) {
		return buffer[stackPtr[stackNum]].value;
	}

	bool isEmpty(int stackNum) {
		return stackPtr[stackNum] == -1;
	}
};


