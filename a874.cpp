#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int adj[50][50] = {0};
        int d[50] = {0};
        bool visited[50] = {0};

        for(int i = 0; i < 50; i++) {
            for(int j = 0; j < 50; j++) {
                adj[i][j] = -1;
            }
        }
        for(int i = 0; i < 50; i++) {
            d[i] = 1e9;
        }

        for(int i = 0; i < n; i++) {
            char a, b;
            int t;
            cin >> a >> b >> t;
            adj[a-'A'][b-'A'] = t;
            adj[b-'A'][a-'A'] = t;
            adj[a-'A'][a-'A'] = 0;
            adj[b-'A'][b-'A'] = 0;
        }
        char start, end;
        cin >> start >> end;

        d[start-'A'] = 0;

        for(int i = 0; i < 50; i++) {
            int a = -1, b = -1, min = 1e9;
            for(int j = 0; j < 50; j++) {
                if(adj[j][j] != -1 && !visited[j] && d[j] < min) {
                    a = j;
                    min = d[j];
                }
            }
            if(a==-1) break;

            visited[a] = true;

            for(int b = 0; b < 50; b++) {
                if(adj[a][b] != -1 && !visited[b] && d[a] + adj[a][b] < d[b]) {
                    d[b] = d[a] + adj[a][b];
                }
            }
        }
        if(d[end-'A'] == 1e9) {
            cout << "NoRoute" << endl;
        }
        else {
            cout << d[end-'A'] << endl;
        }
    }
}