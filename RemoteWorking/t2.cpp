#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
const int maxn = 101;
int n, dp[maxn][maxn], a[maxn][maxn];
signed main(void)
{
    scanf("%lld", &n);
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                dp[1][1] = a[1][1];
            else 
                dp[i][j] = a[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    cout << dp[n][n] << endl;
}