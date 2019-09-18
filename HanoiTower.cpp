#include "HanoiTower.h"

int HanoiTower::nMoves = 0;

int HanoiTower::SolveToH()
{
	Solve(Num_Disks, A, C, B);
	return nMoves;
}

HanoiTower::HanoiTower(int n)
{
	Num_Disks = n;
	A.c = 'A';
	B.c = 'B';
	C.c = 'C';
	for (int i = n; i > 0; i--) {
		A.Stack.push(i);
	}
}

HanoiTower::~HanoiTower()
{
}

void HanoiTower::MoveDisk(ArrayStack<int> &from, ArrayStack<int> &to)
{
	char cto, cfrom;
	int t;
	from.pop(t);
	to.push(t);
	nMoves++;
	Print();
}

void HanoiTower::Print()
{
	cout << "The Towers:\n";
	int t;
	ArrayStack<int> temp;
	cout << "A: ";
	while (A.Stack.pop(t)) {
		temp.push(t);
	}
	while (temp.pop(t)) {
		cout << t << " ";
		A.Stack.push(t);
	}
	cout << "\nB: ";
	while (B.Stack.pop(t)) {
		temp.push(t);
	}
	while (temp.pop(t)) {
		cout << t << " ";
		B.Stack.push(t);
	}
	cout << "\nC: ";
	while (C.Stack.pop(t)) {
		temp.push(t);
	}
	while (temp.pop(t)) {
		cout << t << " ";
		C.Stack.push(t);
	}
	cout << "\n---------------------\n";
}

void HanoiTower::Solve(int n, Peg &from, Peg &to, Peg &aux)
{
	if (n == 1) {
		cout << "Move Disk 1 from " << from.c << " to " << to.c << endl;
		MoveDisk(from.Stack, to.Stack);
		return;
	}

	Solve(n - 1, from, aux, to);

	cout << "Move Disk " << n << " from " << from.c << " to " << to.c << endl;
	MoveDisk(from.Stack, to.Stack);

	Solve(n - 1, aux, to, from);
	
}


