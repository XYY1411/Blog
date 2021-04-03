/*
    (c)2017-2021 XYY1411
*/

#include <cctype>
#include <cstdio>
//#define LOCAL

using namespace std;

typedef long long ll;

template <typename T>  // 教训：不要写默认模版参数
inline T qread(void) {
    T n = 0;
    register char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) n = (n << 1) + (n << 3) + (ch ^ 48), ch = getchar();
    return n;
}

ll divide(int n, int k) {  // n：被分解的数，k：要除的数
    if (n == 1)
        return 1;
    else if (k == 1)
        return 0;
    else if (n % k == 0)
        return divide(n, k - 1) + divide(n / k, k);
    else
        return divide(n, k - 1);
}

int n, a;

int main() {
#ifndef LOCAL
    freopen("div.in", "r", stdin);
    freopen("div.out", "w", stdout);
#endif
    n = qread<int>();
    while (n--) {
        a = qread<int>();
        printf("%lld\n", divide(a, a));
    }
    return 0;
}