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
#define task "tree"
#define INF 2e10
#define mod 1000000007
#define abs(x) ((x)>=0?(x):-(x))
#define fi first
#define se second
typedef int ll;
ll n,t,a[333333],ma[333333],mi[333333],b[333333],c[333333],l[333333],r[333333],w[333333],cur,ch;
void dfs1(ll x)
{
    mi[x]=ma[x]=a[x];
    if(l[x])
        dfs1(l[x]),ma[x]=max(ma[x],ma[l[x]]),mi[x]=min(mi[x],mi[l[x]]);
    if(r[x])
        dfs1(r[x]),ma[x]=max(ma[x],ma[r[x]]),mi[x]=min(mi[x],mi[r[x]]);
}
ll dfs(ll x)
{
    ll l1=0,r1=0;
    l1=c[x];
    if(l[x]+r[x]==0)
    {
        if(!c[x])
            c[x]=a[x]+1;
        if(a[x]>=c[x])
        {
            ch=1;
            return INF;
        }
        return b[x]=c[x]+1;
    }
    if(l[x])
    {
        c[l[x]]=a[x];
        l1=dfs(l[x]);
        if(!c[x])
            c[x]=l1+1;
        if(l1>=c[x])
        {
            ch=1;
            return INF;
        }
    }
    else
    {
        if(!c[x])
            c[x]=a[x]+1;
        if(c[x]<=a[x])
        {
            ch=1;
            return INF;
        }
    }
    if(r[x])
    {
        r1=dfs(r[x]);
        if(mi[r[x]]<=c[x])
        {
            ch=1;
            return INF;
        }
        b[x]=c[r[x]];
    }
    else
    {
        b[x]=c[x]+1;
    }
    if(r[x])
        return r1;
    else
        return b[x];
}
int main()
{
    freopen(task".in","r",stdin);
    freopen(task".out","w",stdout);

    cin>>n>>t;
    for(ll i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i]>>a[i];
        w[l[i]]=w[r[i]]=1;
    }
    for(ll i=1;i<=n;i++)
        if(!w[i])
        cur=i;
    c[cur]=t;
    dfs1(cur);
    t=dfs(cur);
    for(ll i=1;i<=n;i++)
        if(b[i]<1||b[i]>1000000000)
        ch=1;
    if(ch)
    {
        cout<<-1;
        return 0;
    }
    for(ll i=1;i<=n;i++)
        cout<<b[i]<<" ";
}
