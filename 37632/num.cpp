#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
inline int qread() {
    int n = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
    return n;
}
const int maxn = 10;
int T, n, m, map[maxn][maxn];
bool vis[maxn][maxn];
int ans;
inline bool check(int x, int y) {
    for (int i = x - 1; i <= x + 1; ++i)
        for (int j = y - 1; j <= y + 1; ++j)
            if (i <= n && i >= 1 && j <= m && j >= 1)
                if (vis[i][j]) return false;
    return true;
}
inline int dfs(int a, int b) {
    int res = 0;
    int x, y;
    if (a == n && b == m) {
        if (check(a, b))
            return map[a][b];
        else
            return 0;
    }
    if (b == m)
        y = 1, x = a + 1;
    else
        y = b + 1, x = a;
    res = dfs(x, y);
    if (check(a, b)) {
        vis[a][b] = true;
        res = max(res, dfs(x, y) + map[a][b]);
        vis[a][b] = false;
    }
    return res;
}
int main() {
#ifndef LOCAL
    freopen("num.in", "r", stdin);
    freopen("num.out", "w", stdout);
#endif
    T = qread();
    while (T--) {
        n = qread(), m = qread();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                map[i][j] = qread();
        printf("%d\n", dfs(1, 1));
    }
    return 0;
}
