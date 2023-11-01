#include <iostream>
using namespace std;

int n, m;
char a[505][505] = {0};

int dfs(int i, int j, int d) {
    if(i < 0 || i > n || j < 0 || j > m) return d;
    switch(a[i][j]){
        case 'X':
        case 'I':
        case 'H':
        case 'L':
        case '7':
        case 'F':
        case 'J':
        default:
            return d;
    }
}

int main() {
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++) {
            // cnt[i] = 0;
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}