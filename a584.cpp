#include <iostream>
#include <map>
using namespace std;

map<string, string> tree;

int GetDepth(string s) {
    int depth = 0;
    while(tree[s] != "") {
        s = tree[s];
        depth++;
    }
    return depth;
}


int main() {
    int n;
    while(cin >> n) {
        getchar();
        while(n--) {
            string s;
            getline(cin, s);
            string parent = s.substr(0, 3);
            if(tree.find(parent) == tree.end()) {
                tree[parent] = "";
            }
            for(int i = 4; i < s.size(); i+=4) {
                string name = s.substr(i, 3);
                tree[name] = parent;
            }
        }
        string a, b;
        cin >> a >> b;

        int da, db, dp;
        da = GetDepth(a);
        db = GetDepth(b);
        int i = abs(da-db);
        string sa = a, sb = b;
        if(da > db) {
            for(int i = da-db; i > 0; i--) {
                sa = tree[sa];
            }
        }
        else {
            for(int i = db-da; i > 0; i--) {
                sb = tree[sb];
            }
        }
        while(sa != sb) {
            sa = tree[sa];
            sb = tree[sb];
        }
        dp = GetDepth(sa);
        cout << da + db - 2 * dp << endl;
    }
}

