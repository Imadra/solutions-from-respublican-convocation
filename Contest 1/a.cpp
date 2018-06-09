//a
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

int n;
int d[MXN], a[MXN];

llong need[MXN];

bool ok(llong x) {
    for (int i = 2; i < MXN; i++) {
        if (d[i] != i) continue;
        llong cnt = 0;
        llong cur = x;
        while (cur > 1) {
            cur /= i;
            cnt += cur;
        }
        if (cnt < need[i])
            return false;
    }
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    for (int i = 2; i < MXN; i += 2) d[i] = 2;
    for (int i = 3; i * i < MXN; i += 2) {
        if (!d[i]) {
            for (int x = i * i; x < MXN; x += 2 * i)
                d[x] = i;
        }
    }
    for (int i = 2; i < MXN; i++)
        if (!d[i]) d[i] = i;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    for (int i = MXN - 2; i >= 0; i--)
        a[i] += a[i + 1];

    for (int i = 2; i < MXN; i++) {
        if (d[i] != i) continue;
        llong cnt = 0;
        for (llong x = d[i]; x < MXN; x *= (llong) d[i]) {
            for (llong y = x; y < MXN; y += x) {
                cnt += (llong)a[y];
            }
        }
        need[i] = cnt;
    }

    llong l = 1, r = 1e13+1;
    while (r - l > 1) {
        llong m = l + (r - l) / 2;
        if (ok(m)) r = m;
        else l = m;
    }
    if (ok(l)) r = l;
    cout << r;
    return 0;
}
