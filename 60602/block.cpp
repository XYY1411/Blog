#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;
typedef unsigned long long ull;

const int maxn = 3005;
int n, lena, lenb;
ull base=131, cnt = 0;;
char a[maxn], b[maxn], c[maxn];
set<ull> bin;

inline bool have(ull k) {
	if (bin.find(k) == bin.end()) return false;
	else return true;
}

ull bkdrhashs(char* s){
    int len = strlen(s);
    ull ans = 0;
    for (int i = 0; i < len; ++i)
        ans = ans * base + (ull)s[i];
    return ans & 0x7fffffff;
}

inline void init(void) {
	scanf("%d%s%s", &n, a, b);
	lena = n, lenb = n;
}
inline bool check(const char *str) {
	int len = strlen(str);
	int k = 0;
	for (int i = 0; i < lena && k < len; ++i)
		if (a[i] == str[k]) k++;
	if(k >= len) return true;
	else return false;
}
inline void sovle(void) {
	for (int i = 0; i < lenb; ++i)
		for (int j = i; j < lenb; ++j) {
			strncpy(c, &b[i], j - i + 1);
			c[j - i + 1] = '\0';
			ull hash = bkdrhashs(c);
			if (!have(hash)) {
				bin.insert(hash);
				if(check(c)) cnt++;
			}
		}
}

int main() {
#ifndef LOCAL
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
#endif
	init();
	sovle();
	printf("%llu\n", cnt);
	return 0;
}
/*
20
egebejbhcfabgegjgiig
edfbhhighajibcgfecef
*/
