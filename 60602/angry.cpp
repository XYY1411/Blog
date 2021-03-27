#include <cstdio>
#include <cctype>
#include <cstring>
#include <bitset>
#include <iostream>

using namespace std;

typedef unsigned long long ull;
const int maxlogn = 5e5 + 5, maxk = 505;
const ull p = 1e9 + 7;
typedef bitset<maxlogn << 1> bit;

template <typename T>
inline T qread(void) {
	T n = 0;
	register char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = (n << 1) + (n << 3) + (ch ^ 48), \
		ch = getchar();
	return n;
}

char nstr[maxlogn];
int k;
ull a[maxk], n, tmp, ans, nlen;
bit lev;

inline void init(void) {
	scanf("%s%d", nstr, &k);
	nlen = strlen(nstr);
	for (int i = 1; i <= k; ++i) a[i] = qread<ull>();
	for (int i = nlen - 1; i >= 0; --i)
		if (nstr[i] == '1')
			n |= (1 << (nlen - i - 1));
}

inline void sovle(void) {
	ans = 0;
	lev.reset();
	for (ull i = 1; i <= n; i <<= 1) {
		for (ull j = 0; j < i; ++j) {
			if (lev[j]) lev[i + j] = 0;
			else lev[i + j] = 1;
		}
	}
	for (ull i = 0; i < n; ++i)
		if(lev[i]) {
			tmp = 1;
			for (int j = 1; j <= k; ++j) {
				ans = (ans + tmp * a[j] % p) % p;
				tmp = (tmp * i % p) % p;
			}
		}
}

int main() {
#ifndef LOCAL
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
#endif
	init();
	sovle();
	printf("%llu\n", ans);
	return 0;
}
