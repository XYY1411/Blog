#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
template <typename T>
inline T qread() {
  T n = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
  return n;
}
const int maxn = 1e5 + 5;
typedef long long ll;
int n, k;
ll m, res;
struct item {
  ll v;
  ll w;
} t[maxn];
inline bool cmp1(const item &a, const item &b) {
  return a.v <= b.v;
}
inline bool cmp2(const item &a, const item &b) {
  return a.w < b.w ? true : a.w > b.w;
}
int main() {
#ifndef LOCAL
  freopen("bag.in", "r", stdin);
  freopen("bag.out", "w", stdout);
#endif
  n = qread<int>(), m = qread<ll>(), k = qread<int>();
  for (int i = 1; i <= n; ++i) t[i].v = qread<ll>(), t[i].w = qread<ll>();
  sort(t + 1, t + 1 + n, cmp1);
  res = 0;
  for (int i = 1; i <= k; ++i) res += t[i].v;
  if (res > m) {
    puts("-1");
    return 0;
  }
  sort(t + 1, t + 1 + n, cmp2);
  printf("%lld\n", t[(n - 1) >> 1].w);
  return 0; 
}
