/*
   联通性问题 connect
   (c)2017-2021 XYY1411
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2005;
vector<int> e[maxn];
inline void link(int u, int v) {
    e[u].push_back(v);
}
int n, dnf[maxn], cnt = 0, ans = 0;
char ch;
int dfs(int p, int t) {
    dnf[p] = t;
    int res = 1;
    for (int i = 0, lim = e[p].size(); i < lim; ++i)
        if (dnf[e[p][i]] != t) res += dfs(e[p][i], t);
    return res;
}
int main() {
#ifndef LOCAL
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> ch;
            if (ch - '0') link(i, j);
        }
    for (int i = 1; i <= n; ++i) ans += dfs(i, ++cnt);
    cout << ans << endl;
    return 0;
}
