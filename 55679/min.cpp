#include <cstdio>
#include <cctype>
#include <queue>
#include <vector>
#include <algorithm>
#undef LOCAL
using namespace std;
typedef long long ll;
template <typename T>
inline T qread() {
	T n = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = (n << 3) + (n << 1) + (ch ^ 48), ch = getchar();
	return n;
}
int n;
ll ans = 0;
int *fa;
inline int find(int k) {
	while (k != fa[k]) k = fa[k] = fa[fa[k]];
	return k;
}
inline void merge(int a, int b) {
	fa[find(a)] = find(b);
}
struct node {
	int x;
	int y;
	node() {}
	node(int _x, int _y) : x(_x), y(_y) {}
} *p;
inline ll myabs(const ll &a) {
	return a >= 0 ? a : -a;
}
struct edge {
	int u;
	int v;
	ll d;
	edge() {}
	edge(int _u, int _v, ll _d) : u(_u), v(_v), d(_d) {}
};
inline bool operator > (const edge &a, const edge &b) {
	return a.d > b.d;
}
inline ll dis (node &a, node &b) {
	return min(myabs((ll)a.x - b.x), myabs((ll)a.y - b.y));
}
priority_queue<edge, vector<edge>, greater<edge> > pq;
\r
inline void kruskal() {
	int k = 1;
	while (k < n) {
		edge e = pq.top();
		pq.pop();
		int u = e.u, v = e.v;
		ll d = e.d;
		if(find(u) != find(v)) {
			merge(u, v);
			ans += d;
			k++;
		}
	}
}
int main() {
#ifndef LOCAL
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
#endif
	n = qread<int>();
	fa = new int[n + 5];
	p = new node[n + 5];
	int x, y;
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		x = qread<int>(), y = qread<int>();
		p[i] = node(x, y);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ll d = dis(p[i], p[j]);
			pq.push(edge(i, j, d));
			pq.push(edge(j, i, d));
		}
	}
	kruskal();
	printf("%lld\n", ans);
	return 0;
}
\r
