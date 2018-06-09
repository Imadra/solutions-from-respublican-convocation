//j
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
const int MXN = (int) 1e7 + 7;

int n, m;
int d[MXN], a[MXN], b[MXN], ca[MXN], del[MXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    for (int i = 2; i < MXN; i += 2)
        d[i] = 2;
    for (int i = 3; i * i < MXN; i += 2)
    {
        if (!d[i])
        {
            for (int j = i * i; j < MXN; j += 2 * i)
                d[j] = i;
        }
    }
    for (int i = 2; i < MXN; i++)
        if (!d[i])
            d[i] = i;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        while (x > 1)
        {
            int c = d[x];
            while (x % c == 0)
                x /= c, ca[c]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        b[i] = x;
        while (x > 1)
        {
            int c = d[x], cnt = 0;
            while (x % c == 0)
            {
                x /= c;
                if (ca[c])
                {
                    b[i] /= c;
                    ca[c]--;
                    del[c]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        while (x > 1)
        {
            int c = d[x], cnt = 0;
            while (x % c == 0)
            {
                x /= c;
                if (del[c])
                {
                    a[i] /= c;
                    del[c]--;
                }
            }
        }
    }
    cout << n << ' ' << m << "\n";
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << "\n";
    for (int i = 1; i <= m; i++)
        cout << b[i] << ' ';
    cout << "\n";
    return 0;
}
