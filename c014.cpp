#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    long long a, b;
    while(true) {
        cin >> a >> b;
        if(a == 0 && b == 0) break;

        int carry = 0;
        int c = 0; 
        while(a > 0 || b > 0) {
            c = (a % 10 + b % 10 + c) / 10;
            carry += c;
            a /= 10;
            b /= 10;
        }

        if(carry == 0) {
            printf("No carry operation.\n");
        }
        else if(carry == 1) {
            printf("1 carry operation.\n");
        }
        else {
            printf("%d carry operations.\n", carry);
        }
    }
}