#include <iostream>
using namespace std;

int f(int n, int cnt=1) {
    if(n == 1) return cnt;
    cnt++;
    return (n % 2) ? f(3 * n + 1, cnt) : f(n >> 1, cnt);
}

int main() {
    int i, j;
    while(cin >> i >> j) {
        cout << i << " " << j << " ";
        if(i > j)
            swap(i, j);
        int cl = 0;
        for(; i <= j; i++) {
            cl = max(cl, f(i));
        }
        cout << cl << endl;
    }
    return 0;
}