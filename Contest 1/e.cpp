//e
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <bitset>

#define llong long long

#define pb push_back
#define mp make_pair

using namespace std;

const int INF = (int) 1e9 + 7;
const int MXN = (int) 3e8 + 1;

bitset<MXN + 3> u;
int cnt, l, r;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    for (int i = 4; i < MXN; i += 2)
        u[i] = true;
    for (int i = 3; i * i < MXN; i += 2)
    {
        if (!u[i])
        {
            for (int x = i * i; x < MXN; x += 2 * i)
                u[x] = true;
        }
    }
    cin >> l >> r;
    for (int i = 1; i * i <= r; i++)
    {
        for (int j = i + 1; j * j + i * i <= r; j += 2)
        {
            int x = i * i + j * j;
            if (!u[x] && l <= x && x <= r)
            {
                cnt++;
                u[x] = 1;
            }
        }
    }
    if (l <= 2 && r >= 2)
        cnt++;
    cout << cnt;
    return 0;
}
