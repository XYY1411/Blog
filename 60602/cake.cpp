#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, cnt, maxx;

template <typename T>
inline T qread(void) {
	T n = 0;
	register char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = (n << 1) + (n << 3) + (ch ^ 48), \
		ch = getchar();
	return n;
}

template <typename T>
inline T maxn(T a, T b, T c) {
	return max<T>(max<T>(a, b), c);
}

inline void init(void) {
	a = qread<int>(), b = qread<int>(), c = qread<int>();
}

inline void sovle(void) {
	cnt = 0;
	if (a == 0) cnt++;
	if (b == 0) cnt++;
	if (c == 0) cnt++;
	if (cnt == 2) {
		puts("0");
		return;
	}
	if (cnt == 1) {
		if (a == 0) a = b, b = c;
		else if (b == 0) b = c;
		if (a == b) {
			puts("1");
			return;
		}
		puts("2");
		return;
	}
	if (a == b && b == c) {
		puts("2");
		return;
	}
	if (a == b || b == c || a == c) {
		puts("2");
		return;
	}
	maxx = maxn(a, b, c);
	if (maxx == a) {
		if (maxx == (b + c)) {
			puts("2");
			return;
		}
	} else if (maxx == b) {
		if (maxx == (a + c)) {
			puts("2");
			return;
		}
	} else if(maxx == c) {
		if (maxx == (a + b)) {
			puts("2");
			return;
		}
	}
	puts("3");
	return;
}

int main() {
#ifndef LOCAL
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
#endif
	int T;
	T = qread<int>();
	while (T--) {
		init();
		sovle();
	}
	return 0;
}
