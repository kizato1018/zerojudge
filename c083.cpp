#include <iostream>
using namespace std;

int main() {
    int Z, I, M, L;
    int c = 1;
    while(cin >> Z >> I >> M >> L) {
        if (Z == 0 && I == 0 && M == 0 && L == 0) break;
        int nums[10000] = {0};
        int cnt = 0;
        int next = (Z * L + I) % M;
        nums[L] = cnt++;
        while(nums[next] == 0) {
            nums[next] = cnt++;
            next = (Z * next + I) % M;
        }
        cout << "Case " << c++ << ": " << cnt-nums[next] << endl;
    }
}