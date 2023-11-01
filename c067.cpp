#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    int count = 1;
    int brick[100] = {0};
    while(cin >> n && n != 0)
    {
        int total = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> brick[i];
            total += brick[i];
        }

        total /= n;
        
        for(int i = 0; i < n; i++) {
            if(brick[i] > total) {
                ans += brick[i] - total;
            }
        }
        printf("Set #%d\n", count++);
        printf("The minimum number of moves is %d.\n", ans);
        puts("");
    }
}