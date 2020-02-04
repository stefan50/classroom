#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str1[50];
	char str2[50];
	int position_str1 = -1, position_str2 = -1;
	bool flag = false;

	cin >> str1;
	cin >> str2;

	for(int i = 0; (i < strlen(str1)) && !flag; i++) {
		for(int j = 0; j < strlen(str2); j++) {
			if(str1[i] == str2[j]) {
				position_str1 = i;
				position_str2 = j;
				flag = true;
				break;
			}
		}
	}

	if(position_str1 == -1) {
		cout << str1 << endl;
		for(int i = 0; i < strlen(str2); i++) {
			for(int j = 0; j < strlen(str1); j++) {
				cout << " ";
			}
			cout << str2[i] << endl;
		}
	}
	else {
		for(int i = 0; i < strlen(str2); i++) {
			if(i != position_str2) {
				for(int k = 0; k < position_str1; k++) {
					cout << " ";
				}
				cout << str2[i] << endl;
			}
			else {
				cout << str1 << endl;
			}
		}
	}

	return 0;
}
