#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#define mp make_pair
\r
using namespace std;
\r
typedef long long ll;
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
const ll end[] = {102030405060708LL, 910111213141500LL};
const int maxdep = 50;
const int dis[16][2] = {{3, 3}, {0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 0},
                        {1, 1}, {1, 2}, {1, 3}, {2, 0}, {2, 1}, {2, 2},
                        {2, 3}, {3, 0}, {3, 1}, {3, 2}};
typedef pair<ll, ll> pll;
typedef pair<ll, pll> pp;
typedef map<pll, ll> mpp;
\r
int tb[4][4], x, y, nx, ny;
ll ns[2], n[2], v, nv;
mpp m;
priority_queue<pp, vector<pp>, greater<pp> > pq;
inline ll think(int v, int x, int y) {
    return abs(x - dis[v][0]) + abs(y - dis[v][1]);
}
inline bool check(void) {
    if (ns[0] == end[0] && ns[1] == end[1])
        return true;
    else
        return false;
}
\r
inline void ft(void) {  // fill table
    ll k1 = n[0], k2 = n[1];
    for (int j = 3; j >= 0; --j) {
        tb[1][j] = k1 % 100, k1 /= 100;
        tb[3][j] = k2 % 100, k2 /= 100;
        if (tb[1][j] == 0)
            x = 1, y = j;
        else if (tb[3][j] == 0)
            x = 3, y = j;
    }
    for (int j = 3; j >= 0; --j) {
        tb[0][j] = k1 % 100, k1 /= 100;
        tb[2][j] = k2 % 100, k2 /= 100;
        if (tb[0][j] == 0)
            x = 0, y = j;
        else if (tb[2][j] == 0)
            x = 2, y = j;
    }
}
\r
inline void fn(void) {  // fill number
    ns[0] = ns[1] = 0;
    for (int j = 0; j < 4; ++j) {
        ns[0] = ns[0] * 100 + tb[0][j];
        ns[1] = ns[1] * 100 + tb[2][j];
    }
    for (int j = 0; j < 4; ++j) {
        ns[0] = ns[0] * 100 + tb[1][j];
        ns[1] = ns[1] * 100 + tb[3][j];
    }
}
\r
int main() {
#ifndef LOCAL
    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);
#endif
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) scanf("%d", &tb[i][j]);
    fn();
    m[mp(ns[0], ns[1])] = 0;
    nv = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) nv += think(tb[i][j], i, j);
    pq.push(mp(nv, mp(ns[0], ns[1])));
    while (!pq.empty()) {
        pp k = pq.top();
        pq.pop();
        n[0] = k.second.first, n[1] = k.second.second, v = k.first;
        if (m[mp(n[0], n[1])] > maxdep) {
            puts("NO");
            return 0;
        }
        ft();
        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > 3 || ny > 3) continue;
            swap(tb[x][y], tb[nx][ny]);
            fn();
            if (!m.count(mp(ns[0], ns[1]))) {
                nv = 0;
                for (int i = 0; i < 4; ++i)
                    for (int j = 0; j < 4; ++j) nv += think(tb[i][j], i, j);
                pq.push(mp(v + nv, mp(ns[0], ns[1])));
                m[mp(ns[0], ns[1])] = m[mp(n[0], n[1])] + 1;
            }
            if (check()) break;
            swap(tb[x][y], tb[nx][ny]);
        }
        if (check()) break;
    }
    printf("%lld\n", m[mp(ns[0], ns[1])]);
    return 0;
}