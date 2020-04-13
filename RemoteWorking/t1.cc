#include <iostream>
#include <string>
using namespace std;
int t, i, j, dp[1010];
string s;
bool check(int l, int r)
{
    string s2 = s.substr(l,r-l+1);
    string s3(s2.rbegin(),s2.rend());
    return s2 == s3;
}
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        cin >> s;
        for (int& i: dp)i = &i-dp;
        for (i = 0; i < s.size(); i++)
            if (check(0, i))
                dp[i] = 0;
            else for (j = 1; j <= i; j++)
                if (check(j, i))
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                    
        printf("%d\n",dp[s.size()-1]);
    }
    return 0;
}