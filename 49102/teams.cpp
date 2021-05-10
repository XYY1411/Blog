#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long int ull;
int k, lim = 0, tmp, ans = -1;
ull team[25][3];
char str[55];
bool nek[25][25], flag = false;
ull stringhash(const char* s) {
  int len = strlen(s);
  ull n = 0;
  const static ull bas = 131;
  for (int i = 0; i < len; ++i)
    n = n * bas + (ull)s[i];
  return n;
}
int main () {
#ifndef LOCAL
  freopen("teams.in", "r", stdin);
  freopen("teams.out", "w", stdout);
#endif
  scanf("%d", &k);
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= 3; ++j) {
      scanf("%s", str);
      team[i][j] = stringhash(str);
    }
  for (int i = 1; i < k; ++i)
    for (int j = i + 1; j <= k; ++j) {
      flag = false;
      for (int a = 1; a <= 3; ++a)
        for (int b = 1; b <= 3; ++b)
          if (team[i][a] == team[j][b]) {
            flag = true;
            goto found;
          }
found:
      if (flag)
        nek[i][j] = nek[j][i] = false;
      else
        nek[i][j] = nek[j][i] = true;
    }
  for (int i = 1; i <= k; ++i) nek[i][i] = false;
  lim = (1 << k);
  for (int s = 0; s < lim; ++s) {
    flag = true;
    for (int i = 0; i < k - 1; ++i)
      if (s & (1 << i))
        for (int j = i + 1; j < k; ++j)
          if (s & (1 << j))
            if (!nek[i + 1][j + 1]) {
              flag = false;
              goto check;
            }
check:
    if (flag) {
      tmp = 0;
      for (int i = 0; i < k; ++i) {
        if (s & (1 << i)) tmp++;
      }
      ans = max(ans, tmp);
    }
  }
  printf("%d\n", ans);
  return 0;
}
