#include <iostream>

using namespace std;
using functions = double (*)(double);

double return_1(double num) {
    return 1 + num;
}

double return_2(double num) {
    return 2 + num;
}

double return_3(double num) {
    return 3 + num;
}

double return_4(double num) {
    return 4 + num;
}

double return_5(double num) {
    return 5 + num;
}

int main() {
    int num = 0;
    functions f[5];
    f[0] = &return_1;
    f[1] = &return_2;
    f[2] = &return_3;
    f[3] = &return_4;
    f[4] = &return_5;

    cin >> num;
    int max = f[0](num), index = 0;
    for(int i = 0; i < 5; i++) {
        int curr = f[i](num);
        if(curr > max) {
            max = curr;
            index = i;
        }
    }
    cout << index << endl;
    return 0;
}