/*
    (c)2017-2021 XYY1411
*/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
//#define LOCAL
\r
using namespace std;
\r
typedef long long ll;
typedef long double ld;
const int maxn = 1e5;
const ld esp = 1e-8;
ld inf = 0x3f3f3f3f;
\r
template <typename T>
inline T abs(const T& a) {
    return a >= 0 ? a : -a;
}
\r
template <typename T>
inline int cmp(const T& x, const T& y) {
    return abs<T>(x - y) <= esp ? 0 : (x < y ? -1 : 1);
}
\r
template <typename T>
inline T qread(void) {
    T n = 0;
    bool flag = false;
    register char ch = getchar();
    while (!isdigit(ch) && ch != '-') ch = getchar();
    if (ch == '-') flag = true, ch = getchar();
    while (isdigit(ch)) n = (n << 1) + (n << 3) + (ch ^ 48), ch = getchar();
    if (flag)
        return -n;
    else
        return n;
}
\r
int n, m;
ll h[maxn], x0, s[maxn], x[maxn];
ll a[maxn], b[maxn], d1[maxn], d2[maxn], min1, min2, tmp;
ll ans;
\r
inline void init(void) {
    n = qread<int>();
    for (int i = 1; i <= n; ++i) h[i] = qread<ll>();
    x0 = qread<ll>();
    m = qread<int>();
    for (int i = 1; i <= m; ++i) s[i] = qread<ll>(), x[i] = qread<ll>();
}
\r
inline void pre(void) {
    for (int i = n - 1; i > 0; --i) {
        min1 = i + 1, min2 = 0;
        d1[i] = abs<ll>(h[i] - h[i + 1]);
        for (int j = i + 2; j <= n; ++j) {
            tmp = abs<ll>(h[i] - h[j]);
            if (d1[i] > tmp || d1[i] == tmp && h[j] < h[min1])
                d2[i] = d1[i], d1[i] = tmp, min2 = min1, min1 = j;
            else if (d2[i] > tmp || d2[i] == tmp && h[j] < h[min2] ||
                     d2[i] == 0)
                d2[i] = tmp, min2 = j;
        }
        a[i] = min1, b[i] = min2;
    }
}
\r
inline void sovle(void) {
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll ta = 0, tb = 0, k = i;
        bool flag = false;
        while (true) {
            if (flag) {
                if (ta + tb + d1[k] > x0 || !a[k]) break;
                tb += d1[k], k = a[k];
            } else {
                if (ta + tb + d2[k] > x0 || !b[k]) break;
                ta += d2[k], k = b[k];
            }
            flag = !flag;
        }
        if (!ans || cmp<ld>((ld)ta / tb, inf) == -1 ||
            cmp<ld>((ld)ta / tb, inf) == 0 && h[ans] < h[i]) {
            inf = (ld)ta / tb;
            ans = i;
        }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= m; ++i) {
        ll ta = 0, tb = 0;
        bool flag = false;
        while (true) {
            if (flag) {
                if (ta + tb + d1[s[i]] > x[i] || !a[s[i]]) break;
                tb += d1[s[i]];
                s[i] = a[s[i]];
            } else {
                if (ta + tb + d2[s[i]] > x[i] || !b[s[i]]) break;
                ta += d2[s[i]];
                s[i] = b[s[i]];
            }
            flag = !flag;
        }
        printf("%lld %lld\n", ta, tb);
    }
}
\r
int main() {
#ifndef LOCAL
    freopen("drive.in", "r", stdin);
    freopen("drive.out", "w", stdout);
#endif
    init();
    pre();
    sovle();
    return 0;
}