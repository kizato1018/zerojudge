#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    while(n--) {
        string s;
        getline(cin, s);
        stack<char> st;
        bool flag = true;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if(st.empty() || (st.top() == '(' && s[i] != ')') || (st.top() == '[' && s[i] != ']')) {
                    flag = false;
                    break;
                }
                st.pop();
            }
        }
        
        if(flag && st.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }

}