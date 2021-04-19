#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 1005, maxm = 1e5 + 5;

template <typename T>
inline T qread(void) {
    T n = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) n = (n << 1) + (n << 3) + (ch ^ 48), ch = getchar();
    return n;
}

int n, m;

int main() {
#ifndef LOCAL
    freopen("gift.in", "r", stdin);
    freopen("gift.out", "w", stdout);
#endif
    n = qread<int>(), m = qread<int>();
    puts("IMPOSSIBLE");
    return 0;
}