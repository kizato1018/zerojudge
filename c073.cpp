#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int blocks[25][25] = {0};
        int block_cnt[25] = {0};
        int block_pos[25][2] = {0};
        string cmd1;
        int a, b;
        string cmd2;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                blocks[i][j] = -1;
            }
            blocks[i][0] = i;
            block_cnt[i] = 1;
            block_pos[i][0] = i;
            block_pos[i][1] = 0;
        }

        while(cin >> cmd1 && cmd1 != "quit") {
            cin >> a >> cmd2 >> b;
            int ax = block_pos[a][0];
            int bx = block_pos[b][0];
            int ay = block_pos[a][1];
            int by = block_pos[b][1];
            if(ax == bx) continue;

            if(cmd1 == "move") {
                for(int i = ay+1; i < block_cnt[ax]; i++) {
                    int tmp = blocks[ax][i];
                    block_pos[tmp][0] = tmp;
                    block_pos[tmp][1] = block_cnt[tmp];
                    blocks[tmp][block_cnt[tmp]++] = tmp;
                }
                block_cnt[ax] = ay + 1;
            }

            if (cmd2 == "onto") {
                for(int i = by+1; i < block_cnt[bx] ; i++) {
                    int tmp = blocks[bx][i];
                    block_pos[tmp][0] = tmp;
                    block_pos[tmp][1] = block_cnt[tmp];
                    blocks[tmp][block_cnt[tmp]++] = tmp;
                }

                block_cnt[bx] = by + 1;
            }

            for(int i = ay; i < block_cnt[ax]; i++) {
                int tmp = blocks[ax][i];
                block_pos[tmp][0] = bx;
                block_pos[tmp][1] = block_cnt[bx];
                blocks[bx][block_cnt[bx]++] = tmp;
            }
            block_cnt[ax] = ay;

            // cout << cmd1 << " " << a << " " << cmd2 << " " << b << endl;
        }
        for(int i = 0; i < n; i++) {
            cout << i << ": ";
            for(int j = 0; j < block_cnt[i]; j++) {
                cout << blocks[i][j] << " ";
            }
            cout << endl;
        }

        // cout << endl;
    }
}