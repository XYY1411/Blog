#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;
inline int qread() {
    int n = 0;
    bool flag = false;
    char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') flag = true, c = getchar();
    while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
    return flag ? -n : n;
}
const int maxn = 55;
int n, m, q;
int x1, x2, y_1, y2;
int pre[maxn][maxn];
int map[maxn][maxn];
int f[maxn];
int work() {
    int ans = INT_MIN;
    for (int i = x1; i <= x2; i++) {
        memset(f, 0, sizeof(f));
        for (int j = i; j <= x2; j++) {
            int dp = 0, ans2 = INT_MIN;
            for (int k = y_1; k <= y2; k++) {
                f[k] += map[j][k];
                if (dp > 0)
                    dp += f[k];
                else
                    dp = f[k];
                ans2 = max(ans2, dp);
            }
            ans = max(ans, ans2);
        }
    }
    return ans;
}
int main() {
    n = qread(), m = qread(), q = qread();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) map[i][j] = qread();
    for (int i = 1; i <= q; ++i) {
        x1 = qread(), y_1 = qread(), x2 = qread(), y2 = qread();
        printf("%d\n", work());
    }
    return 0;
}