#include <iostream>

using namespace std;

template <typename T>
using doubleFunc = T (*)(T);

template <typename T>
T f(T num) {
    return num + 1;
}

template <typename T>
T g(T num) {
    return num + 2;
}

template <typename T>
double fmax(doubleFunc<T> f, doubleFunc<T> g, double x) {
    int num1 = f(x);
    int num2 = g(x);
    if(num1 > num2) return num1; else return num2;
}

int main() {
    cout << fmax<double>(&f<double>, &g<double>, 5.0);
    return 0;
}