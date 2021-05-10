#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
typedef double db;
int n;
struct point {
  db x;
  db y;
  point(db x = 0, db y = 0) : x(x), y(y) {}
} p[maxn], s[maxn];

struct vector {
  db x;
  db y;
  vector() {}
  vector(const point &a, const point &b) : x(b.x - a.x), y(b.y - a.y) {}
};
double cross(vector a, vector b) {
  return a.x * b.y - b.x * a.y;
}
inline double dis(const point &a, const point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline bool cmp(const point &a, const point &b) {
  db tmp = cross(vector(p[1], a), vector(p[1], b));
  if (tmp > 0) return true;
  if (tmp == 0 && dis(p[0], a) < dis(p[0], b)) return true;
  return false;
}
bool flag = false;
db ans = 0;
int main() {
#ifndef LOCAL
  freopen("demon.in", "r", stdin);
  freopen("demon.out", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    db x, y;
    scanf("%lf%lf", &x, &y);
    p[i] = point(x, y);
    if (y < p[1].y) {
      swap(p[i], p[1]);
    }
    if (y != p[1].y) flag = true;
  }
  if (!flag) {
    puts("0");
    return 0;
  }
  sort(p + 2, p + 1 + n, cmp);
  s[1] = p[1];
  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    while (cnt > 1 && cross(vector(s[cnt - 1], s[cnt]), vector(s[cnt], p[i])) <= 0) cnt--;
    cnt++;
    s[cnt] = p[i];
  }
  for (int i = 2; i < cnt; ++i) ans += cross(vector(s[1], s[i]), vector(s[1], s[i + 1]));
  printf("%lld\n", (long long)(ans / 2 / 50));
  return 0;
}
