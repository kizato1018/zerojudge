#include <iostream>
using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        int cnt = 0;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == ' ' && s[i+1] == ' ')
                cnt++;
        }
    }
}