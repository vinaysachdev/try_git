#include <vector>

using namespace std;

template<typename T>
class ThreeStacks {
	vector<T> threeInOne;
	const int stackSize = 300;
	int stackPtr[3] = {-1, stackSize-1, 2*stackSize -1};
public:
	ThreeStacks() {
		threeInOne.reserve(stackSize*3);
		cout<<"stackptr[0]: "<<stackPtr[0]<< " stackPtr[1]: "<<stackPtr[1]<<endl;
	}

	void push(int stackNum, T val) {
		int stackTop = (stackNum + 1)*stackSize - 1;
		if(stackPtr[stackNum] < stackTop) {
			stackPtr[stackNum]++;
			threeInOne[stackPtr[stackNum]] = val;
		}
		else
			cout<<"Stack "<<stackNum <<" is full"<<endl;
	}

	void pop(int stackNum) {
		if(!isEmpty(stackNum)){
			stackPtr[stackNum]--;
		}
		else {
			cout<< "Stack "<< stackNum <<" is empty";
		}
	}

	// precondition: isEmpty is false
	T& top(int stackNum) {
		return threeInOne[stackPtr[stackNum]];
	}

	bool isEmpty(int stackNum) {
		return stackPtr[stackNum] == stackNum*stackSize - 1;
	}
};
