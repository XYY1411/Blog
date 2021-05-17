#include <algorithm>
#include <cctype>
#include <cstdio>
#include <set>
#include <vector>
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
struct node {
    bool flag;
    ll h;
    node(ll h, bool type) : h(h), flag(type) {}
    node() {}
};
vector<node> line[maxn];
multiset<ll, greater<ll> > nh;
int n;
ll a, b, h, mina = 2147483647, maxb = 0, ans = 0;
inline void insert(ll h) { nh.insert(h); }
inline void remove(ll h) { nh.erase(nh.find(h)); }
int main() {
#ifndef LOCAL
    freopen("horizon.in", "r", stdin);
    freopen("horizon.out", "w", stdout);
#endif
    n = qread<int>();
    for (int i = 1; i <= n; ++i) {
        a = qread<ll>(), b = qread<ll>(), h = qread<ll>();
        if (a == b) continue;
        mina = min(mina, a), maxb = max(maxb, b);
        line[a].push_back(node(h, false)), line[b].push_back(node(h, true));
    }
    for (int i = 0, lim = line[mina].size(); i < lim; ++i)
        insert(line[mina][i].h);
    for (int i = mina + 1; i <= maxb; ++i) {
        if (!nh.empty()) ans += *nh.begin();
        for (int j = 0, lim = line[i].size(); j < lim; ++j) {
            if (line[i][j].flag)
                remove(line[i][j].h);
            else
                insert(line[i][j].h);
        }
    }
    printf("%lld\n", ans);
    return 0;
}