#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
template <typename T>
inline T qread() {
    T n = 0;
    bool flag = false;
    char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') flag = true, c = getchar();
    while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
    return flag ? -n : n;
}
ll x[maxn], pre[maxn];
int n;
ll f[maxn];
ll q[maxn], l = 1, r = 1; // deque
ll a, b, c;
/*
inline ll calc(ll k) {
    return a * k * k + b * k + c;
}
*/
inline double calc(ll j, ll k) { // calc slope
    return double((f[j] - f[k] + a * (pre[j] * pre[j] - pre[k] * pre[k]) + b * (pre[k] - pre[j]))) / (2.0 * a * (pre[j] - pre[k]));
}
int main() {
#ifndef LOCAL
    freopen("commando.in", "r", stdin);
    freopen("commando.out", "w", stdout);
#endif
    n = qread<int>();
    a = qread<ll>(), b = qread<ll>(), c = qread<ll>();
    for (int i = 1; i <= n; ++i) x[i] = qread<ll>(), pre[i] = pre[i - 1] + x[i];
/*
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            f[i] = max(f[i], f[j] + calc(pre[i] - pre[j]));
*/
    for (int i = 1; i <= n; ++i) {
        while (l < r && calc(q[l], q[l + 1]) <= double(pre[i])) l++; // pop head
        ll j = q[l], sum = pre[i] - pre[j];
        f[i] = f[j] + a * sum * sum + b * sum + c;
        while (l <= r && calc(q[r - 1], q[r]) >= calc(q[r], i)) r--; // pop tail;
        q[++r] = i;
    }
    printf("%lld", f[n]);
    return 0;
}
