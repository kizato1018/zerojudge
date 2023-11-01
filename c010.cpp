#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int n;
    while(cin >> n) {v.insert(lower_bound(v.begin(), v.end(), n), n);
        int len = v.size();
        if(len & 1) 
            cout << v[len >> 1] << endl;
        else
            cout << (v[(len >> 1) - 1] + v[len >> 1]) / 2 << endl; 
    }
}