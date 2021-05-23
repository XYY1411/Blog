#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
template <typename T>
inline T qread() {
  T n = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
  return n;
}
int n, q, x, y, *s, *t;
ll *pre;
void fill(const int &n) {
  for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + i;
}
inline int lc(const int &p) { return p << 1; }
inline int rc(const int &p) { return p << 1 | 1; }
inline int mid(const int &l, const int &r) { return (l + r) >> 1; }
void build(int p, int l, int r) {
  s[p] = l, t[p] = r;
  if (l != r) {
    int m = mid(l, r);
    build(lc(p), l, m);
    build(rc(p), m + 1, r);
  }
}
inline ll query(int x, int y) {
  return pre[min(t[y], x)] - pre[min(s[y] - 1, x)];
}
int main() {
#ifndef LOCAL
  freopen("seg.in", "r", stdin);
  freopen("seg.out", "w", stdout);
#endif
  n = qread<int>(), q = qread<int>();
  s = new int[n << 2], t = new int[n << 2];
  pre = new ll[n + 5];
  fill(n);
  build(1, 1, n);
  while (q--) {
    x = qread<int>(), y = qread<int>();
    printf("%lld\n", query(x, y));
  }
  return 0;
}
