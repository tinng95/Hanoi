#include "Tower.h"



Tower::Tower()
{
	cout << "Enter the number of disks: ";
	cin >> n;
	r = n;
	counter = 1;
	//put n in peg Start
	for (int i = 0; i < n; i++)
	{
		Start.push(n - i);
	}

	hanoiStart(Start, Aux1, Aux2, Aux3, Aux4, Destination, counter);
}


void Tower::move(stack<int>& source, stack<int>& dest, int& counter) {
	int temp = source.top();
	source.pop();
	dest.push(temp);
	counter++;
}

void Tower::hanoiStart(stack<int>& start, stack<int>& source, stack<int>& dest, stack<int>& aux, stack<int>& last, stack<int>& last2, int& counter)
{
	move(start, source, counter);
	// correct to here
	H1(Start, Aux1, Aux3, Aux2, Aux4, Destination, counter);
	/*
	start  = Start
	source = Aux1
	dest   = Aux3
	aux    = Aux2
	last   = Aux4
	*/
	//move(dest, last, counter);
}

void Tower::display()
{
	cout << " Start Stack :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!Start.empty()) {
			cout << Start.top() << endl;
			Start.pop();
		}
	}
	cout << endl;
	cout << " Aux1 Stack :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!Aux1.empty()) {
			cout << Aux1.top() << endl;
			Aux1.pop();
		}
	}

	cout << endl;
	cout << " Aux2 Stack :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!Aux2.empty()) {
			cout << Aux2.top() << endl;
			Aux2.pop();
		}
	}
	cout << endl;
	cout << " Aux3 Stack :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!Aux3.empty()) {
			cout << Aux3.top() << endl;
			Aux3.pop();
		}
	}
	cout << endl;
	cout << " Aux4 Stack :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!Aux4.empty()) {
			cout << Aux4.top() << endl;
			Aux4.pop();
		}
	}
	cout << endl;

}

int Tower::H1(stack<int>& start, stack<int>& source, stack<int>& dest, stack<int>& aux, stack<int>& last, stack<int>& last2, int& counter)
{
	/*
	start  = Start
	source = Aux1
	dest   = Aux3
	aux    = Aux2
	last   = Aux4
	*/
	if (source.size() == 1) {
		move(source, aux, counter);
		move(aux, dest, counter);
	}
	else if (source.size() == 2) {
		move(source, aux, counter);
		move(aux, dest, counter);
		//checking
	}

	if (this->counter == 4) {
		move(Start, source, this->counter);
		move(source, aux, this->counter);
		move(dest, aux, this->counter);
		move(aux, source, this->counter);
		move(aux, dest, this->counter);
		if (this->r == 2) {
			move(dest, last, this->counter);
		}
		move(source, aux, counter);
		move(aux, dest, counter);
	}

	else if (source.size() > 2) {
		counter = H1(start, source, dest, aux, last, last2, counter);
		//if (this.hasItMoved[numOfDisks] != 1) 
		if (source.empty()) {
			move(start, source, counter);
			//this.hasItMoved[numOfDisks] = 1;
		}
		move(source, aux, counter);
		counter = H1(start, dest, source, aux, last, last2, counter);
		move(aux, dest, counter);
		if (!dest.empty()) {
			move(dest, last, counter);
		}
		if (source.top() == r) {
			r--;
		}
		counter = H1(Start, source, dest, aux, last, last2, counter);
	};
	return counter;
}

int main() {

	Tower tower = Tower();
	tower.display();

	system("Pause");
	return 0;
}