#pragma once
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Tower
{
public:
	Tower();

	/*
	void move(stack<int>& currentPeg, stack<int>& nextPeg, int& counter);

	void hanoiStart(stack<int>& start, stack<int>& aux1, stack<int>& aux2, stack<int>& aux3, stack<int>& aux4, stack<int>& dest, int& counter);

	

	int H1(stack<int>& start, stack<int>& aux1, stack<int>& aux2, stack<int>& aux3, stack<int>& aux4, stack<int>& dest, int& counter);
	*/
	void H1(int source, int dest, int& counter);

	void hanoiStart();

	void move(int currentPeg, int nextPeg, int& counter);

	void display();

private:

	stack<int> peg[5];
	int r;
	stack<int> Start;
	stack<int> Aux1;
	stack<int> Aux2;
	stack<int> Aux3;
	stack<int> Aux4;
	stack<int> Destination;
	int counter;
	int n;

};

