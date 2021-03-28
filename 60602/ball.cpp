#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int as[5][5];
int bs[5][5];
int n, m, q, x, y, a, b, c, d;
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
	n = qread<int>(), m=qread<int>(), q=qread<int>();
	for (int i = 1; i <= m; ++i) {
		x = qread<int>(), y = qread<int>();
		as[x][y] = 1;
	}
}
inline void sovle(void) {
	memset(bs, 0, sizeof bs);
	a = qread<int>(), b = qread<int>(), c = qread<int>(), d = qread<int>();
	bs[a][b] = 3;
	bs[c][d] = 3;
	if (a == c && b == d) {
		puts("0");
	} else if (a == c && b != d || b == d && a != c){
		puts("1");
	} else if (a != c && b != d) {
		if (as[a][d] == 1 && as[b][c] == 1) {
			puts("-1");
		} else {
			puts("2");
		}
	}
}
int main() {
#ifndef LOCAL
	freopen("ball.in","r",stdin);
	freopen("ball.in","w",stdout);
#endif
	init();
	while (q--) sovle();
	return 0;
}

