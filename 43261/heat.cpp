#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 255;
int tb[maxn][maxn], ans[maxn];
int n, t;
int main() {
#ifndef LOCAL
    freopen("heat.in", "r", stdin);
    freopen("heat.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) tb[i][n + 1] = 1;
    for (int i = 1; i <= n; ++i) {
        while ((scanf("%d", &t), ~t)) {
            tb[t][i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int r = i;
        for (int j = i + 1; j <= n; ++j)
            if (tb[r][i] < tb[j][i]) r = j;
        if (i != r) swap(tb[i], tb[r]);
        int div = tb[i][i];
        for (int j = i; j <= n + 1; ++j) tb[i][j] /= div;
        for (int j = i + 1; j <= n; ++j) {
            div = tb[j][i];
            for (int k = i; k <= n + 1; ++k) tb[j][k] ^= tb[i][k] * div;
        }
    }
    ans[n] = tb[n][n + 1];
    for (int i = n - 1; i >= 1; --i) {
        ans[i] = tb[i][n + 1];
        for (int j = i + 1; j <= n; ++j) ans[i] ^= tb[i][j] * ans[j];
    }
    for (int i = 1; i <= n; ++i)
        if (ans[i])
            printf("%d ", i);
    return 0;
}
