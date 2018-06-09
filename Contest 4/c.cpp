#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string mult(string s, string x)
{
    int a=0,b=0,c[100000],d[100000],e=0,f[100000]= {0},g,h,j,i,k,l=0;

    a=s.size();
    b=x.size();
    reverse (s.begin(),s.end());
    reverse (x.begin(),x.end());
    for(i=0; i<a; i++)
    {
        c[i]=(int)(s[i])-48;
    }
    for(j=0; j<b; j++)
    {
        d[j]=(int)(x[j])-48;
    }
    for(i=0; i<b; i++)
    {
        l=i;
        e=0;
        for(j=0; j<a; j++)
        {
            e=e+(d[i]*c[j]);
            f[l]+=(e%10);
            e=e/10;
            e+=(f[l]/10);
            f[l]%=10;
            l++;
        }
        f[l]=e;
    }
    string res;
    if(f[l]>0)
    {
        while(f[l]!=0)
        {
            int x = (f[l]%10)+48;
            res.push_back(char(x));
            f[l]/=10;
        }
    }
    for(i=l-1; i>=0; i--)
    {
        int x = f[i]+48;
        res.push_back((char)(x));
    }
    return res;
}
int main()
{
    string s,x;
    cin>>s>>x;
    cout<<mult(s, x);
    return 0;
}
