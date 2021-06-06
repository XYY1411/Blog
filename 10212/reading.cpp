/*
   阅读理解 reading
   (c)2017-2021XYY1411
*/
#include <cstdio>
#include <cctype>
using namespace std;
typedef unsigned long long ull;
int n, q, v, *a;
int sum = 0, op, id, u, l, r, d;
ull prod;
inline int qread() {
    int n = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
    return n;
}
int main() {
#ifndef LOCAL
    freopen("reading.in", "r", stdin);
    freopen("reading.out", "w", stdout);
#endif
    n = qread(), q = qread(), v = qread();
    a = new int[n + 5];
    for (int  i = 1; i <= n; ++i) a[i] = qread();
    for (int i = 1; i <= q; ++i) {
        op = qread();
        if (op == 1) {
            id = qread(), u = qread();
            u ^= sum;
            a[id] = u;
        } else if (op == 2) {
            l = qread(), r = qread(), d = qread();
            d ^= sum;
            prod = 1;
            for (int  i = l; i <= r; ++i) prod = prod * a[i] % d;
            if (prod % d == 0)
                puts("Yes"), sum += v;
            else
                puts("No");
        }
    }
    return 0;
}
