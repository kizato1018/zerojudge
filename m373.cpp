#include <iostream>

using namespace std;

int a[150005] = {0};
int dp[25][150005] = {0};
int main() {
    int n, k;
    while(cin >> n >> k) {

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(a, 0, sizeof(dp));
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= k; i++) {
            for(int j = 1; j <= n; j++) {
                if(i > 0) dp[i][j] = dp[i-1][j-1];
                dp[i][j] = max(dp[i][j-1] + a[j-1], dp[i][j]); 
            }
        }
        int ans = 0;
        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= n; j++) {
                ans = max(ans, dp[i][j]);
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }

        cout << ans << endl;
    }
}