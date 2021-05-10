#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxl = 1e6 + 5;
const ll mod = 1e9 + 7;
int n;
char str[maxl];
int next[maxl], ans[maxl];
ll num;
inline void getfail(const char *s) {
  memset(next, 0, sizeof next);
  int len = strlen(s), i, j;
  j = ans[0] = 0, ans[1] = 1;
  for (i = 1; i < len; ++i) {
    while (j && (s[i] != s[j])) j = next[j];
        j += (s[i] == s[j]);
        next[i + 1] = j, ans[i + 1] = ans[j] + 1;
     }
}
inline void getnum(const char *s, int *fail) {
  int i, j = 0, len = strlen(s);
  num = 1;
  for (i = 1; i < len; ++i) {
    while (j &&(s[i] != s[j])) j = fail[j];
    j += (s[i] == s[j]);
    while ((j << 1) > i + 1) j = fail[j];
    num = (num * (ll)(ans[j] + 1)) % mod;
  }
}
int main() {
#ifndef LOCAL
  freopen("zoo.in", "r", stdin);
  freopen("zoo.out", "w", stdout);
#endif
  scanf("%d", &n);
  while (n--) {
    scanf("%s", str);
    getfail(str);
    getnum(str, next);
    printf("%lld\n", num);
  }
  return 0;
}
