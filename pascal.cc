#include <iostream>

using namespace std;

int func(int row, int pos) {
	if(pos > row) return 0;
	if(pos == row || pos <= 0) return 1;
	return func(row - 1, pos) + func(row - 1, pos - 1);
}

int main() {
	int n = 5;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cout << func(i, j) << " ";
		}
		cout << endl;
	}
	return 0;
}
