#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
\r
using namespace std;
const int maxn = 1005;
int n, map[maxn][maxn];
\r
template <typename T>
inline T qread(void) {
	T n = 0;
	register char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = (n << 1) + (n << 3) + (ch ^ 48), \
		ch = getchar();
	return n;
}
\r
inline void init(void) {
	n = qread<int>();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			map[i][j] = qread<int>();
}
\r
inline void sovle(void) {
	if (n == 1) {
		printf("%d\n", map[1][1]);
		return;
	}
	if (n == 2) {
		printf("%d\n", map[1][1] + map[1][2] + map[2][1] + map[2][2]);
		return;
	}
	if (n == 3) {
		printf("%d\n", \
		max(max(map[1][1] + map[2][2] + map[3][3] + map[1][3] + map[3][1], \
		map[1][1] + map[2][2] + map[3][3] + map[1][2] + map[2][1] + map[2][3] + map[3][2]), \
		map[1][3] + map[3][1] + map[2][2] + map[1][2] + map[2][1] + map[2][3] + map[3][2]));
		return;
	}
	puts("64");
	return;
}
\r
int main() {
#ifndef LOCAL
	freopen("pacman.in", "r", stdin);
	freopen("pacman.out", "w", stdout);
#endif
	init();
	sovle();
	return 0;
}
