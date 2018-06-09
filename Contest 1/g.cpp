//g
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
const int MXN = (int) 1e5 + 7;

int n;
int a[MXN], b[MXN], prv[MXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        int ans = 0;
        for (int d = 1; d * d <= a[i]; d++)
        {
            if (a[i] % d)
                continue;
            if (prv[d] < i - b[i])
                ans++;
            if (d * d != a[i] && prv[a[i] / d] < i - b[i])
                ans++;
        }
        for (int d = 1; d * d <= a[i]; d++)
        {
            if (a[i] % d)
                continue;
            prv[d] = prv[a[i] / d] = i;
        }
        cout << ans << "\n";
    }
    return 0;
}
