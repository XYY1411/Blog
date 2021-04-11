#include<cstdio>
#include<cctype>
#undef LOCAL
#include<algorithm>
using namespace std;
template <typename T>
inline T qread() {
	T n = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = (n << 3) + (n << 1) + (ch ^ 48), ch = getchar();
	return n;
}
const int maxn = 1005;
int n, m, ans, l, r, c, cnt = 0;
bool vis[maxn];
struct node {
    int l;
	int r;
	int c;
	node() {}
	node(int _l, int _r, int _c) : l(_l), r(_r), c(_c) {}
} a[maxn];
inline bool cmp(node &a, node &b) {
    return a.r < b.r;
}
int main() {
#ifndef LOCAL
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
#endif
    m = qread<int>();
    for (int i = 1; i <= m; ++i) {
    	l = qread<int>(), r = qread<int>(), c = qread<int>();
    	a[i] = node(l, r, c);
	}
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; ++i) {
    	cnt = 0;
        for (int j = a[i].l; j <= a[i].r; ++j)
			if (vis[j]) cnt++;
		if (cnt < a[i].c) 
		    for (int j = a[i].r; j >= a[i].l; --j) {
		        if(!vis[j]) {
				    cnt++, ans++;
				    vis[j] = true;
				    if(cnt == a[i].c)
				    	break;
				}
		    }
	}
    printf("%d\n", ans);
    return 0;
}
