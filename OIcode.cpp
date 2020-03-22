#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int N = 50010;
int primes[N], cnt;
bool st[N];


using ll = long long;
using PII = pair<int, int>;
PII factor[N];
int divider[N];
int cntf, cntd;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void get_primes(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!st[i])primes[cnt++] = i;
		for(int j = 0;primes[j] <= n/i;j++)
		{
			st[i * primes[j]] = true;
			if (!(i % primes[j]))break;
		}
	}
}
void dfs(int u, int p)
{
	if (u == cntf)
	{
		divider[cntd++] = p;
		return;
	}
	for (int i = 0; i <= factor[u].second; i++)
	{
		dfs(u + 1, p);
		p *= factor[u].first;
	}
}
int main()
{
	get_primes(N - 1);
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a0, a1, b0, b1;
		scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
		cntf = 0;
		int d = b1;
		for (int i = 0; primes[i] <= d / primes[i]; i++)
		{
			int p = primes[i];
			if (!(d % p))
			{
				int s = 0;
				while (!(d % p))
					d /= p, s++;
				factor[cntf++] = make_pair(p, s);

			}
		}
		if (d > 1)factor[cntf++] = make_pair(d, 1);
		cntd = 0;
		dfs(0, 1);
		int res = 0;
		for (int i = 0; i < cntd; i++)
		{
			int x = divider[i];
			if (gcd(x, a0) == a1 && (ll)x / gcd(x, b0) * b0 == b1)res ++;
		}
		printf("%d\n", res);
	}
}