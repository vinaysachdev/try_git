#include <vector>
#include <stack>

template<typename T>
class StackOfStacks {
	const int MAX_SIZE;
	vector<stack<T>> vecStacks;
public:
	StackOfStacks(int size) : MAX_SIZE(size) {
		stack<T> newStack;
		vecStacks.push_back(newStack);	
	}

	// presondition size of vector is atleast 1
	void push(T val) {
		int noOfStacks = vecStacks.size();
		if(vecStacks[noOfStacks].size() == MAX_SIZE) {
			stack<T> newStack;
			vecStacks.push_back(newStack.push(val));
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
		if(noOfStacks > 1 && vecStacks[noOfStacks].size() == 0)
			vecStacks.pop_back();
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
