#include <stack>

class StackWithMin {
	stack<int> s;
	stack<int> minStack;

public:
	void push(int val) {
		if(minStack.empty() || minStack.top() >= val)
				minStack.push(val);
		s.push(val);
	}

	void pop() {
		if(! s.empty()) {
			if(s.top() == minStack.top())
				minStack.pop();
			s.pop();
		}
	}

	int top() {
		return s.top();
	}

	int min() {
		return minStack.top();
	}

	bool empty() {
		return s.empty();
	}
};
