#include <iostream>
using namespace std;

int DFS(string &s, int n, int &i) {
    if(s[i] == '0') { i++; return 0;}
    else if(s[i] == '1') {i++; return n * n;}
    n >>= 1;
    i++;
    return DFS(s, n, i) + DFS(s, n, i) + DFS(s, n, i) + DFS(s, n, i);
}

int main() {
    string s;
    int n;
    while(cin >> s >> n){
        int i = 0;
        cout << DFS(s, n, i) << endl;
    }
}