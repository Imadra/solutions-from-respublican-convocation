//b
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

#define llong long long

#define pb push_back
#define mp make_pair

using namespace std;

const int INF = (int) 1e9 + 7;
const int MXN = (int) 1e5 + 7;

int n;
int a[MXN], d[MXN];

llong ans;
vector<int> p;


void rec(int pos, int cur)
{
    if (cur == 1)
    {
        llong cur = 1;
        for (int i = 0; a[i]; i++)
        {
            for (int x = 0; x < a[i] - 1; x++)
            {
                if (cur * 1LL * p[i] >= ans)
                    return;
                cur = cur * 1LL * p[i];
            }
        }
        if (!ans)
            ans = cur;
        else
            ans = min(ans, cur);
    }
    else
    {
        for (int i = 2; i <= cur; i++)
        {
            if (cur % i == 0)
            {
                a[pos] = i;
                rec(pos + 1, cur / i);
                a[pos] = 0;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        d[i] = i;
        for (int x = 2; x * x <= i; x++)
        {
            if (i % x == 0)
            {
                d[i] = x;
                break;
            }
        }
        if (d[i] == i)
            p.push_back(i);
    }
    ans = 1000000000000000000LL;
    rec(0, n);
    cout << ans;
    return 0;
}
