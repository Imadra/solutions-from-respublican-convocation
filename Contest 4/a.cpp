#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool used[21][21];
int n, x1, y3, x2, y2, n1 = 0;
queue<int> cht;
queue<int> x;
queue<int> y;
void bfs();
int main()
{
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            used[i][j] = false;
    cin >> n;
    cin >> x1 >> y3;
    cin >> x2 >> y2;
    if (x1 == x2 && y3 == y2)
    {
        cout << "0" << endl;
        cout << x1 << " " << y3;
        return 0;
    }
    bfs();
    cout << n1;
    return 0;
}
void vpk(int v1, int v2, int v3)
{
    if (v1 - 2 > 0 && v2 - 1 > 0)
    {
        x.push(v1 - 2);
        y.push(v2 - 1);
        cht.push(v3);
    }
    if (v1 - 2 < n && v2 + 1 < n)
    {
        x.push(v1 - 2);
        y.push(v2 + 1);
        cht.push(v3);
    }
    if (v1 + 2 < n && v2 + 1 < n)
    {
        x.push(v1 + 2);
        y.push(v2 + 1);
        cht.push(v3);
    }
    if (v1 + 2 < n && v2 - 1 > 0)
    {
        x.push(v1 + 2);
        y.push(v2 - 1);
        cht.push(v3);
    }
    if (v1 + 1 < n && v2 + 2 < n)
    {
        x.push(v1 + 1);
        y.push(v2 + 2);
        cht.push(v3);
    }
    if (v1 - 1 > 0 && v2 - 2 > 0)
    {
        x.push(v1 - 1);
        y.push(v2 - 2);
        cht.push(v3);
    }
    if (v1 - 1 > 0 && v2 + 2 < n)
    {
        x.push(v1 - 1);
        y.push(v2 + 2);
        cht.push(v3);
    }
    if (v1 + 1 < n && v2 - 2 > 0)
    {
        x.push(v1 + 1);
        y.push(v2 - 2);
        cht.push(v3);
    }
}
void bfs()
{
    cht.push(n1);
    x.push(x1);
    y.push(y3);
    while(!x.empty() && !y.empty())
    {
        int v1 = x.front();
        x.pop();
        int v2 = y.front();
        y.pop();
        int v3 = cht.front();
        cht.pop();
        if(used[v1][v2])
            continue;
        used [v1][v2] = true;
        v3 = v3 + 1;
        if((v1 - 2 == x2 && v2 - 1 == y2) || (v1 + 2 == x2 && v2 + 1 == y2) || (v1 - 2 == x2 && v2 + 1 == y2) || (v1 + 2 == x2 && v2 - 1 == y2) || (v1 - 1 == x2 && v2 - 2 == y2) || (v1 + 1 == x2 && v2 + 2 == y2) || (v1 + 1 == x2 && v2 - 2 == y2) || (v1 - 1 == x2 || v2 + 2 == y2))
        {
            n1 = v3;
            break;
        }
        vpk(v1,v2,v3);
    }
}
