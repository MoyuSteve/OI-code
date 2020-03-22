#include<stdio.h>
#define int long long

const int N = 3000;
int c[N][N];
int s[N][N];
signed main()
{
	int T,k;
	scanf("%lld%lld",&T,&k);
	for(int i = 0;i < N;i++)
		for(int j = 0;j<=i;j++)
		{
			if (!j)c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
			if(!c[i][j]) s[i][j] = 1;
		}
	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
		{
			if(i)s[i][j] += s[i-1][j];
			if(j)s[i][j] += s[i][j-1];
			if(i&&j)s[i][j] -= s[i-1][j-1];
		}
	while(T--)
	{
		int n,m;
		scanf("%lld%lld",&n,&m);
		printf("%lld",s[n][m]);
	}
}
