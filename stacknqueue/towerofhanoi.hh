#include <stack>
#include<iostream>

using namespace std;

class Tower {
	stack<int> stackOfdisks;
	int index;
public:
	Tower(int i):index(i) {}

	int getIndex() { return index;}

	void addTo(int disk) {
		if(! stackOfdisks.empty() && disk >= stackOfdisks.top())
			std::cout<<"Error pacing disk: "<<disk<<std::endl;
		else {
			stackOfdisks.push(disk);
		}
	}

	void moveTopTo(Tower& t) {
		int topDisk = stackOfdisks.top();
		stackOfdisks.pop();
		t.addTo(topDisk);
		std::cout<<"Move disk"<<topDisk<<" from tower "<<getIndex()<<" to tower "<<t.getIndex()<<std::endl;
	}

	void moveDisks(int n, Tower& destination, Tower& buffer) {
		if(n > 0) {
			moveDisks(n-1, buffer, destination);
			moveTopTo(destination);
			buffer.moveDisks(n-1, destination, *this);
		}
	}

	void printTower() {
		
	}
};
