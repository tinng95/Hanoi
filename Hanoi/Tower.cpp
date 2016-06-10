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
		peg[0].push(n - i);
	}

	hanoiStart();
}

void Tower::H1(int source, int dest, int & counter)
{
	if (peg[source].size() == 1) {
		for (int i = source; source < dest; i++) {
			move(i, i + 1, counter);
		}
	}

	if (peg[source].size() >= 2) {
		for (int i = source; source < dest; i++) {
			move(i, i + 1, counter);

			//changes
		}
	}
}

void Tower::hanoiStart()
{
	H1(0, 5, counter);

}

void Tower::move(int currentPeg, int nextPeg, int & counter)
{
	int temp = peg[currentPeg].top();
	peg[currentPeg].pop();
	peg[nextPeg].push(temp);
	counter++;
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

int main() {
	Tower tower = Tower();
	tower.display();

	system("Pause");
	return 0;
}