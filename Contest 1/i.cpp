//I
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

llong n, ans = -1;

int getsum(llong x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    cin >> n;
    for (llong s = 1; s < 100; s++) {
        llong d = s * s + 4 * n;
        if (d < 0) continue;
        llong cur;
        cur = (-s + sqrt(d)) / 2LL;
        if (cur > 0 && getsum(cur) == s && cur * cur + cur * s == n) {
            if (ans == -1) ans = cur;
            else ans = min(ans, cur);
        }

        cur = (-s - sqrt(d)) / 2LL;
        if (cur > 0 && getsum(cur) == s && cur * cur + cur * s == n) {
            if (ans == -1) ans = cur;
            else ans = min(ans, cur);
        }
    }
    cout << ans;

    return 0;
}
