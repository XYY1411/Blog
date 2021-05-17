#include <cctype>
#include <cstdio>
using namespace std;
template <typename T>
inline T qread() {
    T n = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) n = (n << 3) + (n << 1) + (ch ^ 48), ch = getchar();
    return n;
}
const int maxn = 1e5 + 5;
typedef long long ll;
const ll mod = 1e9 + 7;
int fa[maxn];
int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}
void merge(int x, int y) { fa[find(x)] = find(y); }
int n, m, l1, r1, l2, r2;
ll ans;
template <typename T>
inline T qpow(T b, T p, T mod) {
    T s = 1;
    while (p > 0) {
        if (p & 1) s = s * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return s % mod;
}
int main() {
#ifndef LOCAL
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
#endif
    n = qread<int>(), m = qread<int>();
    ans = n;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i) {
        l1 = qread<int>(), r1 = qread<int>();
        l2 = qread<int>(), r2 = qread<int>();
        int len = r1 - l1;
        for (int j = 0; j <= len; ++j) {
            int f1 = find(l1 + j), f2 = find(l2 + j);
            if (f1 != f2) {
                merge(l1 + j, l2 + j);
                ans--;
            }
        }
    }
    ans = 9 * qpow<ll>(10, ans - 1, mod) % mod;
    printf("%lld\n", ans);
    return 0;
}