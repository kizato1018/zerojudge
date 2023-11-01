#include<iostream>
#include<queue>
using namespace std;

int main() {
    int W, H, L;
    while(cin >> W >> H >> L) {
        getchar();
        char Map[1000][1000] = {0};
        bool visited[1000][1000] = {0};
        queue<pair<int, int>> q;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                Map[i][j] = getchar();
                if(Map[i][j] == 'S') {
                    q.push(pair<int, int>(i, j));
                }
            }
            getchar();
        }
        int leng = 0;
        while(!q.empty() && leng++ < L) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                pair<int, int> pos = q.front();
                q.pop();
                if(visited[pos.first][pos.second]) continue;
                visited[pos.first][pos.second] = true;
                if(Map[pos.first][pos.second] == '#') continue;

                Map[pos.first][pos.second] = '.';
                
                if(pos.first > 0)
                    q.push(pair<int,int>(pos.first-1, pos.second));
                if(pos.first < H-1)
                    q.push(pair<int,int>(pos.first+1, pos.second));
                if(pos.second > 0)
                    q.push(pair<int,int>(pos.first, pos.second-1));
                if(pos.second < W-1)
                    q.push(pair<int,int>(pos.first, pos.second+1));
            }
        }

        bool isFired = false;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j <= W; j++) {
                cout << Map[i][j];
                isFired |= Map[i][j] == 'F';
            }
            cout << endl;
        }
        if(!isFired)
            cout << endl << "All Fires Extinguished!" << endl;
    }
}