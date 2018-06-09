//L
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

int t, n;

bool prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;

    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    cin >> t;
    while (t--) {
        cin >> n;
        int prv = n, nxt = n + 1;
        while (!prime(prv)) prv--;
        while (!prime(nxt)) nxt++;
        llong u = 1LL * (prv - 2) * nxt + 2LL * (n - prv + 1);
        llong d = 2LL * prv * nxt;
        llong G = __gcd(u, d);
        u /= G, d /= G;
        cout << u << "/" << d << "\n";
    }
    return 0;
}
