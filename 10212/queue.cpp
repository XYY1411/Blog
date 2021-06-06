/*
   K优先队列 queue
   (c)2017-2021 XYY1411
*/
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
inline int qread() {
    int n = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
    return n;
}
typedef vector<int> v;
typedef vector<int>::iterator vit;
v que;
int n, k, p, opt, x, last = 0;
void insert(int x) {
    vit it = lower_bound(que.begin(), que.end(), x);
    que.insert(it, x);
}
int pop(int x) {
	vit it = que.end() - x;
	int k = *it;
	return que.erase(it), k;
}
int main() {
#ifndef LOCAL
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
#endif
    n = qread(), k = qread(), p = qread();
    que.reserve(n + 5);
    while (n--) {
        opt = qread();
        switch (opt) {
            case 1: x = qread(); if (p) x ^= last; insert(x); break;
            case 2: last = pop(k); printf("%d\n", last); break;
        }
    }
}
