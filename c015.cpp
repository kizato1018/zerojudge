#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        string rs = "0";
        int count = 1;
        cin >> s;

        rs = s;
        reverse(rs.begin(), rs.end());
        s = to_string(stoi(s) + stoi(rs));
        rs = s;
        reverse(rs.begin(), rs.end());
        
        while(s != rs) {
            s = to_string(stoi(s) + stoi(rs));
            rs = s;
            reverse(rs.begin(), rs.end());
            count++;
        }
        cout << count << " " << s << endl;
    }
}