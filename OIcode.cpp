#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int mod = 10007;
int pow(int a, int x)
{
	int r = 1;
	while (x)
	{
		if (x & 1)r = r * a % mod;
		a = a * a % mod; x >>= 1;
	}
	return r;
}
signed main(void)
{
	int a, b, k, n, m;
	cin >> a >> b >> k >> n >> m;
	int r = pow(a, n) * pow(b, m) % mod;
	for (int i = 1, j = k; i <= n; i++, j--)
		r = r * j % mod, r = r * pow(i, mod - 2) % mod;
	cout << r;
	return 0;
}