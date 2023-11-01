#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    for(int c = 1; c <= T; c++) {
        int N;
        int a, b;
        int high = 0, low = 0;
        cin >> N;
        cin >> a;
        for(int i = 1; i < N; i++) {
            cin >> b;
            if(a < b) 
                high++;
            else if(a > b) 
                low++;
            a = b;
        }
        cout << "Case " << c << ": " << high << " " << low << endl;
    }
}