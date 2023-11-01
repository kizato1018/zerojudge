#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n;
    printf("PERFECTION OUTPUT\n");
    while(cin >> n && n != 0) {
        printf("%5d  ", n);
        
        int sum = (n > 1);
        for(int i = 2; i <= (int) sqrt(n); i++)
            sum += (n % i) ? 0 : i + n/i;
        if(sum == n)
            printf("PERFECT\n");
        else if (sum < n)
            printf("DEFICIENT\n");
        else
            printf("ABUNDANT\n");
        

    }
    printf("END OF OUTPUT");
}