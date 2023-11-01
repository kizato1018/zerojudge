#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool cmp(pair<char, int>& a, pair<char, int>& b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int n = 0;
    string s;
    map<char, int> table;
    vector<pair<char, int>> out;
    cin >> n;
    getline(cin, s);
    while(n--) {
        getline(cin, s);
        for(char c : s) {
            if(isalpha(c)) {
                c = toupper(c);
                table[c] = (table.find(c) != table.end()) ? table[c] + 1 : 1;
            }
        } 
    }
    for(auto& it : table) {
        out.push_back(it);
    }
    sort(out.begin(), out.end(), cmp);
    for(auto& it : out) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}