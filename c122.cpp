#include <cstdio>
#include <algorithm>
using namespace std;

int mmin(int a, int b, int c, int d) {
    return min(a, min(b, min(c, d)));
}

int main() {
    int humble_number[6000] = {0, 1};
    int a2 = 1, a3 = 1, a5 = 1, a7 = 1;
    for(int i = 2; i <= 5842; i++) {
        humble_number[i] = mmin(humble_number[a2] * 2, humble_number[a3] * 3, humble_number[a5] * 5, humble_number[a7] * 7);
        if(humble_number[i] == humble_number[a2] * 2) a2++;
        if(humble_number[i] == humble_number[a3] * 3) a3++;
        if(humble_number[i] == humble_number[a5] * 5) a5++;
        if(humble_number[i] == humble_number[a7] * 7) a7++;
    }
    int n;
    while(scanf("%d", &n)!=EOF && n != 0) {
        if(n % 10 == 1 && n % 100 != 11) 
            printf("The %dst humble number is %d.\n", n, humble_number[n]);
        else if(n % 10 == 2 && n % 100 != 12) 
            printf("The %dnd humble number is %d.\n", n, humble_number[n]);
        else if(n % 10 == 3 && n % 100 != 13) 
            printf("The %drd humble number is %d.\n", n, humble_number[n]);
        else
            printf("The %dth humble number is %d.\n", n, humble_number[n]);
    }
}