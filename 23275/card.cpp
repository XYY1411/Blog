/*
    (c)2017-2021 XYY1411
*/

#include <cctype>
#include <cstdio>
//#define LOCAL

using namespace std;

typedef long long ll;

template <typename T>
inline T qread(void) {
    T n = 0;
    bool flag = false;
    register char ch = getchar();
    while (!isdigit(ch) && ch != '-') ch = getchar();
    if (ch == '-') flag = true, ch = getchar();
    while (isdigit(ch)) n = (n << 1) + (n << 3) + (ch ^ 48), ch = getchar();
    if (flag)
        return -n;
    else
        return n;
}

ll n, pre, ans;

inline void sovle(void) {
    ans = 0, n = qread<ll>(), pre = qread<ll>();
    for (int i = 2; i <= n; ++i) {
        pre += qread<ll>();
        if (pre > 0) ans += pre;
    }
}

inline void print(void) { printf("%lld\n", ans); }

int main() {
#ifndef LOCAL
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
#endif
    sovle();
    print();
    return 0;
}