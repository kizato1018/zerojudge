#include <iostream>
#include <vector>
using namespace std;

int main() {
    // int a[10][10] = {0};
    // for(int i = 0; i < 10; i++) {
    //     for(int j = 0; j < i; j++) {
    //         a[i][j] = i*10+j;
    //     }
    // }
    // for(auto& b : a) {
    //     for(auto& c : b) {
    //         cout << c << " ";
    //     }
    //     puts("");
    // }
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for(int i : v) {
        cout << i << endl;
    }
}