#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 45989, maxn = 105;
struct matrix {
    const static int mod = ::mod;
    const static int maxn = ::maxn;
    int m;
    int n;
    int a[maxn][maxn];
    inline void clear() {
        memset(a, 0, sizeof a);
    }
    matrix(int x, int y) : m(x), n(y) {
        clear();
    }
    friend inline matrix operator*(const matrix &a, const matrix &b) {
        matrix res(a.m, b.n);
        for (int i = 1; i <= a.m; ++i)
            for (int j = 1; j <= b.n; ++j)
                for (int k = 1; k <= a.n; ++k)
                    res.a[i][j] = (res.a[i][j] + a.a[i][k] * b.a[k][j]) % matrix::mod;
        return res;
    }
};
matrix qpow(matrix s, matrix b, int p) {
    while (p > 0) {
        if (p & 1) s = s * b;
        b = b * b;
        p >>= 1;
    }
    return s;
}
int n, m, t, a, b, u, v, ans;
int head[maxn], next[maxn], tot = 0;
struct edge {
    int u;
    int v;
} e[maxn << 1];
inline void link(int u, int v) {
    e[++tot] = (edge){u, v};
    next[tot] = head[u];
    head[u] = tot;
}
inline int odd(int x) { return x % 2 == 0 ? x - 1 : x + 1; }
int main() {
#ifndef LOCAL
    freopen("running.in", "r", stdin);
    freopen("running.out", "w", stdout);
#endif
    scanf("%d%d%d%d%d", &n, &m, &t, &a, &b);
    a++, b++;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        u++, v++;
        link(u, v), link(v, u);
    }
    matrix s(tot, 1), b(tot, tot);
    for (int i = 1; i <= tot; ++i)
        for (int j = head[e[i].v]; j; j = next[j])
            if (odd(i) != j) b.a[j][i] = 1; 
    for (int i = head[a]; i; i = next[i]) s.a[i][1]++;
    b = qpow(b, b, t - 2);
    b = b * s;
    for (int i = head[::b]; i; i = next[i]) ans = (ans + b.a[odd(i)][1]) % mod;
    printf("%d\n", ans);
    return 0;
}
