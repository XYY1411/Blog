#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;
int n, q, l, r, c, d, cnt;
int a[maxn], b[maxn];

template <typename T>
inline T qread(void) {
	T n = 0;
	register char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = (n << 1) + (n << 3) + (ch ^ 48), \
		ch = getchar();
	return n;
}

inline void init(void) {
	n = qread<int>(), q = qread<int>();
	for (int i = 1; i <= n; ++i)
		a[i] = qread<int>(), b[i] = qread<int>();
}

inline void sovle(void) {
	cnt = 0;
	l = qread<int>(), r = qread<int>(), c = qread<int>(), d = qread<int>();
	for (int i = l; i <= r; ++i)
		if ((a[i] ^ c) <= min(b[i], d)) cnt++;
	printf("%d\n", cnt);
}

int main() {
#ifndef LOCAL
	freopen("island.in", "r", stdin);
	freopen("island.out", "w", stdout);
#endif
	init();
	for (int i = 1; i <= q; ++i)
		sovle();
	return 0;
}
