#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
#include<map>
#include<set>
using namespace std;
#define pb push_back
#define mp make_pair
#define task "lesson"
#define INF 2e9
#define mod 1000000007
#define abs(x) ((x)>=0?(x):-(x))
#define fi first
#define se second
typedef long long ll;
ll n,m,a[5555],d[5555]={1},w[5555];
ll gcd(ll a, ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}
int main()
{
    freopen(task".in","r",stdin);
    freopen(task".out","w",stdout);

    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        d[i]=d[i-1];
        if(i>1)
            d[i]+=d[i-2],d[i]%=mod;
        for(ll j=i-2;j>=1&&((a[j]<=a[j+1]&&a[j+1]<=a[j+2]));j--)
        {
            if(!w[j])
            d[i]+=d[j-1],d[i]%=mod,w[j]=1;
        }
        for(ll j=i-2;j>=1&&((a[j]>=a[j+1]&&a[j+1]>=a[j+2]));j--)
        {
            if(!w[j])
            d[i]+=d[j-1],d[i]%=mod,w[j]=1;
        }
        for(ll j=1;j<=i;j++)
            w[j]=0;
    }
    cout<<d[n];
}
