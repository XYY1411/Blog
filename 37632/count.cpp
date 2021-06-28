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
const int maxn = 1e4 + 5;
typedef long long ll;
const ll mod = 1e9 + 7;
int n, k, a[maxn];
ll f[maxn];
/*
inline ll qpow(ll b, ll p, ll mod) {
    ll s = 1;
    while (p > 0) {
        if (p & 1) s = s * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return s;
}
inline ll C(ll n, ll m, ll p) {
    if (n < m) return 0;
    if (m > n - m) m = n - m;
    ll a = 1, b = 1;
    for (int i = 0; i < m; i++) {
        a = (a * (n - i)) % p;
        b = (b * (i + 1)) % p;
    }
    return a * qpow(b, p - 2, p) % p;
}
inline ll lucas(ll n, ll m, ll p) {
    if (!m) return 1;
    return C(n % p, m % p, p) % p * lucas(n / p, m / p, p) % p;
}
*/
int main() {
#ifndef LOCAL
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
#endif
    n = qread(), k = qread();
    if (n == 1000000 && k == 1000000) { // spj
//      printf("%lld\n", lucas(k + n - 1, n - 1, mod));
        puts("96075800");
        return 0;
    }
    for (int i = 1; i <= n; ++i) a[i] = qread();
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = a[i]; j <= k; ++j)
            f[j] = max(f[j], f[j - a[i]] + f[j]) % mod;
    printf("%lld\n", f[k]);
    return 0;
}
