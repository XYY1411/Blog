#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-7;
const int maxn = 105;
double tb[maxn][maxn], ans[maxn];
int n;
int main() {
#ifndef LOCAL
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) scanf("%lf", &tb[i][j]);
        scanf("%lf", &tb[i][n + 1]);
    }
    for (int i = 1; i <= n; ++i) {
        int r = i;
        for (int j = i + 1; j <= n; ++j)
            if (fabs(tb[r][i]) < fabs(tb[j][i])) r = j;
        if (fabs(tb[r][i]) < eps) {
            puts("Wrong Information!");
            return 0;
        }
        if (i != r) swap(tb[i], tb[r]);
        double div = tb[i][i];
        for (int j = i; j <= n + 1; ++j) tb[i][j] /= div;
        for (int j = i + 1; j <= n; ++j) {
            div = tb[j][i];
            for (int k = i; k <= n + 1; ++k) tb[j][k] -= tb[i][k] * div;
        }
    }
    ans[n] = tb[n][n + 1];
    for (int i = n - 1; i >= 1; --i) {
        ans[i] = tb[i][n + 1];
        for (int j = i + 1; j <= n; ++j) ans[i] -= tb[i][j] * ans[j];
    }
    for (int i = 1; i <= n; ++i) printf("%.2lf\n", ans[i]);
    return 0;
}
