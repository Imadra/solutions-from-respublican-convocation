//h
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
int d[MXN];

llong ans;

llong binpow(int x, int y) {
    llong res = 1;
    while (y) {
        if (y & 1)
            res = (res * 1LL * x);

        y >>= 1;
        x = (1LL * x * x);
    }
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    for (int i = 2; i < MXN; i += 2)
        d[i] = 2;

    for (int i = 3; i * i < MXN; i++) {
        if (!d[i]) {
            for (int x = i * i; x < MXN; x += 2 * i)
                d[x] = i;
        }
    }

    for (int i = 2; i < MXN; i++)
        if (!d[i]) d[i] = i;

    cin >> n >> m;
    for (int i = n; i < n + m; i++) {
        int x = i;
        llong s = 1;
        while (x > 1) {
            int p = d[x];
            int cnt = 0;
            while (x % p == 0)
                x /= p, s *= (llong)p, cnt++;

            if (cnt & 1) s /= p;
        }
        ans += i / s;
    }
    cout << ans;
    return 0;
}
