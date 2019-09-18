#pragma once
#include "ArrayStack.h"
#include <iostream>

using namespace std;

class HanoiTower {
private:
	int Num_Disks;
	struct Peg {
		ArrayStack<int> Stack;
		char c;
	};
	Peg A, B, C;
	static int nMoves;
public:
	int SolveToH();
	HanoiTower(int n);
	~HanoiTower();
	void MoveDisk(ArrayStack<int> &from, ArrayStack<int> &to);
	void Print();
	void Solve(int n, Peg &from, Peg &to, Peg &aux);
};