#include <algorithm>
#include <cctype>
#include <cstdio>
#include <queue>
using namespace std;
template <typename T>
inline T qread() {
    T n = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
    return n;
}
const int maxn = 1e5 + 5;
typedef long long ll;
int n, k, cnt, p;
ll m, res;
struct item {
    ll v;
    ll w;
} t[maxn];
inline bool cmp1(const item &a, const item &b) { return a.v < b.v; }
inline bool cmp2(const item &a, const item &b) { return a.w < b.w; }
priority_queue<ll> bag;
int main() {
#ifndef LOCAL
    freopen("bag.in", "r", stdin);
    freopen("bag.out", "w", stdout);
#endif
    n = qread<int>(), m = qread<ll>(), k = qread<int>();
    for (int i = 1; i <= n; ++i) t[i].v = qread<ll>(), t[i].w = qread<ll>();
    sort(t + 1, t + 1 + n, cmp1);
    res = 0;
    for (int i = 1; i <= k; ++i) res += t[i].v;
    if (res > m) {
        puts("-1");
        return 0;
    }
    sort(t + 1, t + 1 + n, cmp2);
    res = 0;
    for (int i = n; cnt < k && i > 0; --i) {
        p++;
        if (res + t[i].v > m && t[i].v > bag.top()) continue;
        while (t[i].v + res > m) {
            if (res + t[i].v > m && t[i].v > bag.top()) continue;
            res -= bag.top(), bag.pop(), cnt--;
        }
        res += t[i].v, bag.push(t[i].v);
        cnt++;
    }
    printf("%lld\n", t[n - (k >> 1) - p + k].w);
    return 0;
}