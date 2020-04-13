#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=111111;
int a[maxn],b[maxn],c[maxn],n;
int main() 
{
    while(cin>>a[n++]);n--;
    int a1=1,a2=1;
    b[0] = c[0] = a[0];
    for(int i=1; i<n; i++) 
    {
        if(b[a1-1]>=a[i])b[a1++]=a[i];
        else *upper_bound(b,b+a1,a[i],greater<int>()) = a[i];
        if(c[a2-1]<a[i]) c[a2++]=a[i];
        else *lower_bound(c,c+a2,a[i]) = a[i];
    }
    cout<<a1<<endl<<a2;
    return 0;
}