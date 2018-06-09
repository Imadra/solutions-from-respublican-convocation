//d
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
int a[MXN], b[MXN];

llong ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    llong cur = 0, sum = 0;
    for (int i = 2; i <= n; i++)
    {
        int d = a[i] - a[i - 1];
        cur += 1LL * (i - 1) * d * d + 2LL * d * sum;
        sum += 1LL * (i - 1) * d;
        ans += cur;
    }
    cur = 0, sum = 0;
    for (int i = 2; i <= n; i++)
    {
        int d = b[i] - b[i - 1];
        cur += 1LL * (i - 1) * d * d + 2LL * d * sum;
        sum += 1LL * (i - 1) * d;
        ans += cur;
    }
    cout << ans;
    return 0;
}
