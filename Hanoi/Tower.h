#pragma once
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Tower
{
public:
	Tower();


	void move(stack<int>& source, stack<int>& dest, int& counter);

	void hanoiStart(stack<int>& start, stack<int>& source, stack<int>& dest, stack<int>& aux, stack<int>& last, stack<int>& last2, int& counter);

	void display();

	int H1(stack<int>& start, stack<int>& source, stack<int>& dest, stack<int>& aux, stack<int>& last, stack<int>& last2, int& counter);
private:

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

