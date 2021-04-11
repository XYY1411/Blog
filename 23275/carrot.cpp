#include <cstdio>
#include <cctype>
#undef LOCAL
using namespace std;
template <typename T>
inline T qread() {
	T n = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = (n << 3) + (n << 1) + (ch ^ 48), ch = getchar();
	return n;
}
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 3e6 + 5;
bool vis[maxn];
int n, m, k, pre[maxn];
ll ans = 0;
int find(int k) {
	if (vis[k]) return pre[k] = find(pre[k]);
	else return k;
}
int main() {
#ifndef LOCAL
	freopen("carrot.in", "r", stdin);
	freopen("carrot.out", "w", stdout);
#endif
	n = qread<int>(), m = qread<int>();
	for (int i = 1; i <= m; ++i) pre[i] = i;
	for (int i = 1; i <= n; ++i) {
		k = qread<int>();
		int j = find(k);
		if (j > 0) {
			vis[j] = true;
			pre[j] = j - 1;
			ans = (ans + i * j % mod) % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
