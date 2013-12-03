#include <stack>

// Queue implemented with two stacks but with lazy approach. Newest element will be pushed to s1
// but PUSH and POP operation access old elements from s2. If s2 is empty, s1 is copied to s2 in 
// reverse order.
template<typename T>
class MyQueue {
	std::stack<T> s1, s2;
public:
	void push(T val) { s1.push(val); }

	int size() { return s1.size() + s2.size(); }
	
	//precondition: queue is not empty
	// worst case complexity is O(n)
	void pop() {
		if(!s2.empty()) s2.pop();
		else {
			while(!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			s2.pop();
		}
	}

	//precondition: queue is not empty
	// worst case complexity is O(n)
	T top() {
		if(!s2.empty()) return s2.top();
		while(!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		return s2.top();
	}

	bool empty() {
		return s1.empty() && s2.empty();
	}
};
