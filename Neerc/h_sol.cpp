#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int maxq = 1344 * 10;

int gcd(int a, int b)
{
    while (b != 0)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int solve(int x, int y, int d)
{
    std::vector <int> divisors;
    for (int i = 1; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            divisors.push_back(i);
            if (i * i != y)
                divisors.push_back(y / i);
        }
    }
    std::sort(divisors.begin(), divisors.end());

    int start = find(divisors.begin(), divisors.end(), x) - divisors.begin();
    int finish = find(divisors.begin(), divisors.end(), y) - divisors.begin();
    //cout<<start<<" "<<finish<<endl;
    std::vector <int> q(maxq);
    int qh = 0, qt = 0;
    q[qt++] = start;
    std::vector <int> distance(divisors.size(), INF);
    distance[start] = 0;
    while (qh != qt)
    {
        int v = q[qh++];
        if (qh == maxq)
            qh = 0;
        for (size_t i = 0; i < divisors.size() && divisors[i] <= d; i++)
        {
            long long newDivisor = divisors[v] * 1LL * divisors[i];
            if (newDivisor > y)
                continue;
            int position = lower_bound(divisors.begin(), divisors.end(), newDivisor) - divisors.begin();
            assert(position < (int)divisors.size());
            if (divisors[position] == newDivisor && distance[position] > distance[v] + 1)
            {
                distance[position] = distance[v] + 1;
                q[qt++] = position;
                if (qt == maxq)
                    qt = 0;
            }
        }
    }
    return distance[finish] == INF ? -INF : distance[finish];
}

int main()
{
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int g = gcd(a, b);
    cout<<solve(g, a, d) <<" "<< solve(g, b, d)<<endl;
    int answer = solve(g, a, d) + solve(g, b, d);
    printf("%d\n", answer < 0 ? -1 : answer);
    return 0;
}
