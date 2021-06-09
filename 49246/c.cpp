#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
int n, m;
ll map[maxn][maxn];
ll l, r, maxx = LLONG_MIN, minx = LLONG_MAX;
ll t[maxn], cnt;
bool vis[maxn][maxn];
inline ll mid(ll l, ll r) { return (l + r + 1) >> 1; }
inline bool check(ll k) {
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        cnt = 0;
        for (int j = 1; j <= m; ++j)
            if (map[i][j] >= k) t[++cnt] = j;
        for (int i = 1; i < cnt; ++i)
            for (int j = i + 1; j <= cnt; ++j) {
                if (vis[t[i]][t[j]])
                    return true;
                else
                    vis[t[i]][t[j]] = true;
            }
    }
    return false;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%lld", &map[i][j]);
            minx = min(minx, map[i][j]);
            maxx = max(maxx, map[i][j]);
        }
    }
    l = minx, r = maxx;
    while (l < r) {
        ll m = mid(l, r);
        if (check(m))
            l = m;
        else
            r = m - 1;
    }
    printf("%lld", l);
    return 0;
}