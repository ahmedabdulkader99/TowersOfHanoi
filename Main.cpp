#include "HanoiTower.h"


int main() {
	cout << "Please Enter the Number of Disks: \n";
	int x;
	cin >> x;
	HanoiTower H(x);
	H.Print();
	cout << "Solution:\n===============\n";
	cout << "Number of Moves: " << H.SolveToH();

	return  0;
}