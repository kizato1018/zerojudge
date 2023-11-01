#include <iostream>
using namespace std;

int n = 0, m = 0;
int a[50][50] = {0};
int score = 0;
bool f(int i, int j) {
    // printf("i:%d j:%d a[i][j]:%d\n", i, j, a[i][j]);
    if(a[i][j] == -1) return false;
    for(int y = 1; i - y >= 0; y++) {
        if(a[i][j] == a[i-y][j]) {
            // printf("i-y:%d j:%d\n", i-y, j);
            score += a[i][j];
            a[i][j] = -1;
            a[i-y][j] = -1;
            return true;
        }
        else if(a[i-y][j] != -1) break;
    }
    for(int y = 1; i + y < n; y++) {
        if(a[i][j] == a[i+y][j]) {
            // printf("i+y:%d j:%d\n", i+y, j);
            score += a[i][j];
            a[i][j] = -1;
            a[i+y][j] = -1;
            return true;
        }
        else if(a[i+y][j] != -1) break;
    }
    for(int x = 1; j - x >= 0; x++) {
        if(a[i][j] == a[i][j-x]) {
            // printf("i:%d j-x:%d\n", i, j-x);
            score += a[i][j];
            a[i][j] = -1;
            a[i][j-x] = -1;
            return true;
        }
        else if(a[i][j-x] != -1) break;
    }
    for(int x = 1; j + x < m; x++) {
        if(a[i][j] == a[i][j+x]) {
            // printf("i:%d j:%d\n", i, j+x);
            score += a[i][j];
            a[i][j] = -1;
            a[i][j+x] = -1;
            return true;
        }
        else if(a[i][j+x] != -1) break;
    }
    return false;
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        score = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        bool update = true;
        while(update) {
            update = false;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    update |= f(i, j); 
                }
            }
        }
        cout << score << endl;
    }
}
