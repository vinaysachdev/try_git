#include <iostream>
#include <cassert>
#include "myqueue.hh"

int main() {
	MyQueue<int> myQueue;
	myQueue.push(2);
	myQueue.push(3);
	assert(myQueue.top() == 2);
	return 0;
}
