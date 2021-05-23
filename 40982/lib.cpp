#include <cctype>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
template <typename T>
inline T qreadi() {
  T n = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) n = (n << 1) + (n << 3) + (c ^ 48), c = getchar();
  return n;
}
inline int qreads() {
  int flag = 0;
  char c = getchar();
  while (!isalpha(c)) c = getchar();
  switch (c) {
    case 'A': flag = 1; break;
    case 'R': flag = 2; break;
    case 'C': flag = 3; break;
    case 'L': flag = 4; break;
    case 'Q': flag = 5; break;
  }
  while (isalpha(c)) c = getchar();
  return flag;
}
int n, t, x, a, b, k;
int v[maxn];
inline void add(int t, int x) {
  v[t] += x;
}
inline int remove(int t) {
  int res = 0;
  for (int i = 1; i < t; ++i) {
    res += v[i];
    v[i] = 0;
  }
  return res;
}
inline int count(int a, int b) {
  int res = 0;
  for (int i = a; i <= b; ++i) res += v[i];
  return res;
}
inline int list(int x) {
  int res = 0;
  for (int i = n; i >= 1; --i) {
    res += v[i];
    if (x <= res) return i;
  }
  return -1;
}
int main() {
#ifndef LOCAL
  freopen("lib.in", "r", stdin);
  freopen("lib.out", "w", stdout);
#endif
  n = qreadi<int>();
  while (true) {
    k = qreads();
    switch(k) {
      case 1: {
        t = qreadi<int>(), x = qreadi<int>();
        add(t, x);
        break;
      }
      case 2: {
        t = qreadi<int>();
        printf("%d\n", remove(t));
        break;
      }
      case 3: {
        a = qreadi<int>(), b = qreadi<int>();
        printf("%d\n", count(a, b));
        break;
      }
      case 4: {
        x = qreadi<int>();
        int ans = list(x);
        if (ans != -1)
          printf("%d\n", ans);
        else
          puts("No");
        break;
      }
      case 5: return 0;
    }
  }
  return 0;
}
