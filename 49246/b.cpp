#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
int n;
struct node {
    ll w;
    ll s;
} kyon[maxn];
ll ans = LLONG_MIN, t = 0;
inline bool cmp(const node &a, const node &b) { return a.w + a.s < b.w + b.s; }
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld%lld", &kyon[i].w, &kyon[i].s);
    sort(kyon + 1, kyon + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, t - kyon[i].s);
        t += kyon[i].w;
    }
    printf("%lld\n", ans);
    return 0;
}