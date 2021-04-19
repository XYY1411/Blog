#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll n, ans = 0x7fffffffffffffffLL, len = -1, tmp;

struct node {
	ll v;
	int k;
} pre[maxn];

inline bool cmp(const node &a, const node &b) {
	return a.v < b.v;
}

template <typename T>
inline T qread(void) {
    T n = 0;
    char ch = getchar();
    bool flag = false;
    while (!isdigit(ch) && ch != '-') ch = getchar();
    if (ch == '-') flag = true, ch = getchar();
    while (isdigit(ch)) n = (n << 1) + (n << 3) + (ch ^ 48), ch = getchar();
    if (flag) n = -n;
    return n;
}

int main() {
#ifndef LOCAL
    freopen("min.in", "r", stdin);
    freopen("min.out", "w", stdout);
#endif
    n = qread<ll>();
    pre[0].v = 0, pre[0].k = 0;
    for (int i = 1; i <= n; ++i) {
    	pre[i].v = pre[i - 1].v + qread<ll>();
    	pre[i].k = i;
	}
    sort (pre, pre + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
    	if ((tmp = abs(pre[i].v - pre[i - 1].v)) < ans) ans = tmp, len = abs(pre[i].k - pre[i - 1].k);
    	else if (tmp == ans) len = max<ll>(len, abs(pre[i].k - pre[i - 1].k));
	}
    printf("%lld\n%lld\n", ans, len);
    return 0;
}