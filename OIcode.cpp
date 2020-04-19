// then 传染病控制 in https://www.nowcoder.com/study/live/249/7/2
//做法：暴力做法

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
const int N = 310, M = N * 2;
 
int n, m;
int head[N], e[M], c[M], nxt[M], cnt;
int sum[N];
vector<int> level[N];
int ans = N;
 
void add(int a, int b)
{
    e[cnt] = b, nxt[cnt] = head[a], head[a] = cnt++;
}
int dfs1(int u, int depth, int father)
{
    sum[u] = 1;
    for (int i = head[u]; ~i; i = nxt[i])
    {
        int j = e[i];
        if (j != father)
        {
            level[depth].push_back(i);
            sum[u] += dfs1(j, depth + 1, u);
        }
    }
    return sum[u];
}
 
void dfs3(int i, int color)
{
    c[i] = color;
    for (int j = head[e[i]]; ~j; j = nxt[j])
        if (j != (i ^ 1))
            dfs3(j, color);
}
 
void dfs2(int u, int s)
{
    ans = min(ans, s);
 
    if (level[u].empty()) return;
 
    for (int j = 0; j < level[u].size(); j++)
    {
        int i = level[u][j];
        if (!c[i])
        {
            dfs3(i, 1);
            dfs2(u + 1, s - sum[e[i]]);
            dfs3(i, 0);
        }
    }
}
 
int main()
{
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs1(1, 0, -1);
    dfs2(0, n);
    printf("%d\n", ans);
    return 0;
}