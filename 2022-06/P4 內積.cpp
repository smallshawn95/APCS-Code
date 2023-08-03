#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001], s[1001], t[1001];

int main()
{
    int n, m, ans = -10001;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < m; i++){
        cin >> t[i];
    }
    for(int i = 0; i < m; i++){
        dp[0][i] = s[0] * t[i];
        ans = max(ans, dp[0][i]);
    }
    for(int i = 0; i < n; i++){
        dp[i][0] = s[i] * t[0];
        ans = max(ans, dp[i][0]);
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = max(0, dp[i - 1][j - 1]) + s[i] * t[j];
            ans = max(ans, dp[i][j]);
        }
    }
    reverse(t, t + m);
    for(int i = 0; i < m; i++){
        dp[0][i] = s[0] * t[i];
        ans = max(ans, dp[0][i]);
    }
    for(int i = 0; i < n; i++){
        dp[i][0] = s[i] * t[0];
        ans = max(ans, dp[i][0]);
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = max(0, dp[i - 1][j - 1]) + s[i] * t[j];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}
