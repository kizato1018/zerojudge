#include <iostream>
using namespace std;

int main() {
    int x, n;
    while(cin >> x >> n) {
        int left = x, right = x;
        int left_cnt = 0, right_cnt = 0;
        int tmp;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            if(tmp < x) {
                left = min(left, tmp);
                left_cnt++;
            }
            else {
                right = max(right, tmp);
                right_cnt++;
            }
        }
        if(left_cnt < right_cnt) {
            cout << right_cnt << " " << right << endl;
        }
        else {
            cout << left_cnt << " " << left << endl;
        }
    }
}