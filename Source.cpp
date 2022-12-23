#include<iostream>
#include<vector>
#include<array>
using namespace std;
int main() {
	const int size = 5;
	int i1, i2 ,p;
	int grid[size][size] = { { 0 } };
	grid[4][4] = 1;
	grid[4][0] = 1;
	grid[0][4] = 1;
	grid[0][0] = 1;
	cout << "choose 1 for computer and 2 for a player" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "enter the index and player number(1/2): ";
				cin >> i1 >> i2>> p;
				if(p==1){
					if ((i1 >= i2)&& grid[i1][i2]==0) {
						grid[i1][i2] = 1;
						for (int s = 0; s < 5; s++) {
							for (int c = 0; c < 5; c++) {
								cout << grid[s][c]<<"  ";
							}
							cout << endl;
						}
					}
					else {
						cout << "wrong";
					}
				}
				else if (p == 2) {
					if ((i1 <= i2) && grid[i1][i2] == 0) {
						grid[i1][i2] = 1;
						for (int s = 0; s < 5; s++) {
							for (int c = 0; c < 5; c++) {
								cout << grid[s][c] << "  ";
							}
							cout << endl;
						}
					}
					else {
						cout << "wrong";
					}
				}
		}
	}
	return 0;
}