#include <cctype>
#include <cstdio>
#include <cstring>
#include <map>
\r
using namespace std;
const int maxn = 1e5 + 5, maxl = 15;
typedef unsigned long long ull;
int n, ans = 0, p[maxn], cnt = 0;
ull s[maxn], t[maxn];
map<ull, int> sm;
map<ull, int>::iterator it;
bool vis[maxn];
inline ull qread(void) {
    const static ull base = 131;
    char ch = getchar();
    ull hash = 0;
    while (!isalnum(ch)) ch = getchar();
    while (isalnum(ch)) hash = hash * base + ch, ch = getchar();
    return hash;
}
int dfs(int k) {
    vis[k] = true, p[k] = cnt;
    it = sm.find(t[k]);
    if (it == sm.end()) return 1;
    int n = sm[t[k]];
    if (!vis[n])
        return dfs(n) + 1;
    else {
        if (p[n] == p[k])
            return 2;
        else
            return 1;
    }
}
int main() {
#ifndef LOCAL
    freopen("files.in", "r", stdin);
    freopen("files.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        s[i] = qread(), t[i] = qread();
        if (s[i] == t[i])
            vis[i] = true;
        else
            sm[s[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) cnt++, ans += dfs(i);
    }
    printf("%d\n", ans);
    return 0;
}