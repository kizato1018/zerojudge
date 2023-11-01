#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int a[1010] = {0};
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int ops = 0;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         ops += (a[i] > a[j]);
        //     }
        // }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n-1; j++) {
                if(a[j] > a[j+1]) {
                    swap(a[j], a[j+1]);
                    ops++;
                }
            }
        }

        printf("Minimum exchange operations : %d\n", ops);
    }
}