#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
template <typename T>
inline T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
struct fact {
    ll u;
    ll d;
    void inline ss(void) {
        ll tmp = gcd(u, d);
        u /= tmp, d /= tmp;
    }
    fact(int u, int d) : u(u), d(d) { ss(); }
};
int n, m, v[maxn], l, r, k;
char op;
template <typename T>
inline T qreadn() {
    T n = 0;
    char ch = getchar();
    bool flag = false;
    while (!isdigit(ch) && ch != '-') ch = getchar();
    if (ch == '-') flag = true, ch = getchar();
    while (isdigit(ch)) n = (n << 3) + (n << 1) + (ch ^ 48), ch = getchar();
    if (flag == true)
        return -n;
    else
        return n;
}
inline char qreadc() {
    char ch = getchar();
    while (!isalpha(ch)) ch = getchar();
    return ch;
}
int main() {
#ifndef LOCAL
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
#endif
    n = qreadn<int>(), m = qreadn<int>();
    for (int i = 1; i <= m; ++i) {
        op = qreadc();
        switch (op) {
            case 'C': {
                l = qreadn<int>(), r = qreadn<int>(), k = qreadn<int>();
                for (int j = l; j < r; ++j) v[j] += k;
                break;
            }
            case 'Q': {
                l = qreadn<int>(), r = qreadn<int>();
                ll u = 0, d = 0;
                if (r < l) swap(r, l);
                for (int a = l; a < r; ++a)
                    for (int b = a + 1; b <= r; ++b) {
                        ++d;
                        for (int j = a; j < b; ++j) u += v[j];
                    }
                fact ff(u, d);
                printf("%lld/%lld\n", ff.u, ff.d);
            }
        }
    }
    return 0;
}