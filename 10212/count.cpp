/*
   简单计数问题 count
   (c) 2017-2021 XYY1411
*/
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>
using namespace std;
const int maxn = 1e5 + 5;
inline int qread() {
    int n = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
    return n;
}
int n, c, m, t, l, r, ans = 0, minn, maxx;
int k, a[maxn], num[maxn];
int main() {
#ifndef LOCAL
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
#endif
    n = qread(), c = qread(), m = qread(), t = qread();
    for (int i = 1; i <= n; ++i) a[i] = qread();
    for (int i = 1; i <= m; ++i) {
        l = qread(), r = qread();
        l = (l + t * ans) % n + 1, r = (r + t * ans) % n + 1;
        if (l > r) swap(l, r);
        ans = 0;
        memset(num, 0, sizeof num);
        minn = LONG_MAX, maxx = LONG_MIN;
        for (int j = l; j <= r; ++j)
            num[a[j]]++, minn = min(a[j], minn), maxx = max(a[j], maxx);
        for (int j = minn; j <= maxx; ++j)
            if (num[j] && (num[j] & 1) == 0) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
