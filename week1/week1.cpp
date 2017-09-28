//
// Created by malthe on 9/14/17.
//

#include <iostream>
#include "week1.h"

using namespace std;


int week1::fibonachi(int n, int c) {

    string indent = "";

    for (int i = 0; i < c; i++) {
        indent += " ";
    }
    cout << indent + "fibonacci(" + to_string(n) + ")"<< endl;
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonachi(n-1, c+4) + fibonachi(n-2, c+4);
}

int week1::power(int base, int n) {
    if(n > 0) {
        //int mult = base * base;
        return base*power(base, n-1);
    }
    return base;
}

int week1::gcd(int a, int b) {
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int week1::simplify(int a, int b) {
    int gcd1 = gcd(a, b);
    if(gcd1!=0) {
        //int fraction1
        cout << (a/gcd1);
        cout << " /";
        cout << a/gcd1;
    }
}

int week1::factorial(int n) {

    if(n == 1) {
        return 1;
    }
    return n*factorial(n-1);

}


