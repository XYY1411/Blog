#include <cstdio>
using namespace std;
int n;
typedef long long ll;
ll k, ans, res;
int main() {
#ifndef LOCAL
    freopen("catfish.in", "r", stdin);
    freopen("catfish.out", "w", stdout);
#endif
    scanf("%d", &n);
    while (n--) {
        scanf("%lld", &k);
        ans = 0ll, res = 1;
        for (int i = 0; k ; ++i, k >>= 1, res *= 3)
            ans += (k & 1) * res;
        printf("%lld\n", ans);
    }
    return 0;
}
