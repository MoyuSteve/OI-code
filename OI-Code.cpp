#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 2555;
int a[maxn], dp[maxn], sum[maxn];
int main()
{
	char c;
	int n, k, x, y;
	cin >> n >> k;
	memset(a, 0, sizeof(a));
	dp[0] = sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		sum[i] = sum[i - 1] + (c == 'H');//H队
		dp[i] = i;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
		{
			x = sum[i] - sum[j - 1];
			y = i - j - x + 1;
			if (y == 0 || x == 0 || abs(x - y) <= k)
				dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	cout << dp[n] << endl;
	return 0;
}