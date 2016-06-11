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
	//start source = 0; dest 3
	if (peg[source].size() == 1) {
		move(source, dest, counter);
	}
	// S A1 A2 A3 A4 Dest
	if (peg[source].size() >= 2) {
		move(source, dest, counter);
		if (dest > 0) {
			H1(source, dest - 1, counter);
		}
		H2(dest, source + 1, counter);
	}
}

void Tower::H2(int source, int dest, int & counter)
{
	//source = 3, dest = 1
	move(source, dest, counter);
	H1(dest + 1, source, counter);
}

void Tower::hanoiStart()
{
	H1(0, 3, counter);

}

void Tower::move(int currentPeg, int destPeg, int & counter)
{
	if (currentPeg < destPeg) {
		for (; currentPeg < destPeg; currentPeg++) {
			int temp = peg[currentPeg].top();
			peg[currentPeg].pop();
			peg[currentPeg + 1].push(temp);
			counter++;
		}
		if (currentPeg > destPeg) {
			for (; currentPeg > destPeg; currentPeg--) {
				int temp = peg[currentPeg].top();
				peg[currentPeg].pop();
				peg[currentPeg - 1].push(temp);
				counter++;
			}
		}
	}
}

void Tower::display()
{
	cout << " Start Stack :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!peg[0].empty()) {
			cout << peg[0].top() << endl;
			peg[0].pop();
		}
	}
	cout << endl;
	cout << " Aux1 Stack :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!peg[1].empty()) {
			cout << peg[1].top() << endl;
			peg[1].pop();
		}
	}

	cout << endl;
	cout << " Aux2 Stack :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!peg[2].empty()) {
			cout << peg[2].top() << endl;
			peg[2].pop();
		}
	}
	cout << endl;
	cout << " Aux3 Stack :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!peg[3].empty()) {
			cout << peg[3].top() << endl;
			peg[3].pop();
		}
	}
	cout << endl;
	cout << " Aux4 Stack :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!peg[4].empty()) {
			cout << peg[4].top() << endl;
			peg[4].pop();
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