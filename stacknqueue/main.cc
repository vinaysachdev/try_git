#include <iostream>
#include <cassert>
#include "threestacks.hh"
#include "threestacks_2.hh"
#include "stackmin.hh"
#include "stackofstacks_2.hh"

using namespace std;

void testThreeStacks();
void testThreeStacks_2();
void testStackWithMin();
void testStackOfStacks();

int main() {
	testThreeStacks();
	testThreeStacks_2();
	testStackWithMin();
	testStackOfStacks();
	return 0;
}

void testThreeStacks() {
	ThreeStacks<int> threestacks;	

	threestacks.push(0,2);
	threestacks.push(0,3);
	threestacks.push(0,4);

	threestacks.push(1,5);
	threestacks.push(1,6);
	threestacks.push(1,7);

	threestacks.push(2,8);
	threestacks.push(2,9);
	threestacks.push(1,10);

	cout <<"Top Element at stack 1: "<<threestacks.top(0)<<endl;
	threestacks.pop(0);
	cout <<"Top Element at stack 1: "<<threestacks.top(0)<<endl;
	threestacks.pop(0);
}

void testThreeStacks_2() {
	ThreeStacksUB<int> threestacks;	
	
	threestacks.push(0,2);
	threestacks.push(0,3);
	threestacks.push(0,4);

	threestacks.push(1,5);
	threestacks.push(1,6);
	threestacks.push(1,7);

	threestacks.push(2,8);
	threestacks.push(2,9);
	threestacks.push(1,10);

	cout <<"ThreeStacksUB: Top Element at stack 1: "<<threestacks.top(0)<<endl;
	threestacks.pop(0);
	cout <<"ThreeStacksUB: Top Element at stack 1: "<<threestacks.top(0)<<endl;
	threestacks.pop(0);
}

void testStackWithMin() {
	StackWithMin s;
	s.push(54);
	s.push(3);
	s.push(32);
	s.push(3);

	cout<<"testStackWithMin: push done"<<endl;
	cout<<"The minimum element is: "<< s.min()<<endl;
	assert(s.min() == 3);
	s.pop();
	cout<<"The minimum element is: "<< s.min()<<endl;
	assert(s.min() == 3);
	s.pop();
	cout<<"The minimum element is: "<< s.min()<<endl;
	assert(s.min() == 3);
	s.pop();
	cout<<"The minimum element is: "<< s.min()<<endl;
	assert(s.min() == 54);
}

void testStackOfStacks() {
	StackOfStacks<int> s(3);
	s.push(54);
	s.push(3);
	s.push(32);
	s.push(3);

}
