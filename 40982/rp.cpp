#include <cstdio>
#include <cctype>
using namespace std;
int n, q, x, y, lx, ly, k;
template <typename T>
inline T qread() {
  T n = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
  return n;
}
inline int getlen(const int &n) {
  int tmp = 1, s = 1;
  while (n & (~s)) s = s << 1 | 1, ++tmp;
  return tmp;
}
int main() {
#ifndef LOCAL
  freopen("rp.in", "r", stdin);
  freopen("rp.out", "w", stdout);
#endif
  n = qread<int>(), q = qread<int>();
  while (q--) {
    x = qread<int>(), y = qread<int>();
    lx = getlen(x), ly = getlen(y);
    k = 0;
//  while (k < lx && k < ly && ((x & (1 << (lx - 1 - k))) >> (lx - 1 - k)) == ((y & (1 << (ly - 1 - k))) >> (ly - 1 - k))) k++;
    while (k < lx && k < ly && (bool(x & (1 << (lx - 1 - k)))) == (bool(y & (1 << (ly - 1 - k))))) k++;
    printf("%d\n", lx - k + ly - k);
  }
  return 0;
}
