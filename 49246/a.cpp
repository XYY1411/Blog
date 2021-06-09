#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;
const int maxn = 1e4 + 5, maxm = 4e5 + 5;
int n, m, t, ans = 0;
int w[maxm];
priority_queue<int> mon;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        mon.push(t);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) scanf("%d", &w[i]);
    sort(w + 1, w + 1 + n);
    for (int i = 1; i <= m; ++i) {
        int x = mon.top();
        if (x < w[i]) continue;
        ans++;
        mon.pop();
        if (x - w[i] > 0) mon.push(x - w[i]);
    }
    printf("%d\n", ans);
    return 0;
}