//f
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <cassert>

#define llong long long

#define pb push_back
#define mp make_pair

using namespace std;

const int INF = (int) 1e9 + 7;
const int MXN = (int) 1e7 + 7;

llong a, b, c;
llong mn = INF;

llong len(llong x)
{
    if (!x)
        return 1;
    llong s = 0;
    while (x > 0)
    {
        s++;
        x /= 10;
    }
    return s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    cin >> a >> b >> c;
    //a = min(a, 999999999LL);
    //b = min(b, 999999999LL);
    for (llong i = 0; i <= min(a, c); i++)
    {
        llong x = (i * 1000000000LL) % c;
        llong y = (c - x) % c;
        assert((x + y) % c == 0);
        if (y > b)
        {
            cout << 1 << " ";
            for (int j = 0; j < 9 - len(i); j++)
                cout << 0;

            cout << i;
            return 0;
        }
    }
    cout << 2;
    return 0;
}
