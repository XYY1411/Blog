---
title: 并查集
author: XYY1411
copyright:
  enable: true
  type: CC BY-NC-SA 4.0
  url: 'https://creativecommons.org/licenses/by-nc-sa/4.0/deed.zh'
carrier: false
description: '并查集是一种用于快速查询处理一些元素与集合的查询与合并的数据结构。'
excerpt: '并查集是一种用于快速查询处理一些元素与集合的查询与合并的数据结构。'
keywords: 并查集
tag: 并查集
category:
  - 计算机科学
  - 数据结构
toc: true
image: /images/ice-flower.jpg
date: '2021-12-11 14:26:08'
abbrlink: 61809
---

## 简介

**并查集**（英语：**Disjoint-set data structure**、**disjoint-set data structure** 或 **merge–find set**），是一种用于快速查询处理一些元素与集合的查询与合并的数据结构。

支持以下几种操作：

- 查询：查询某个元素属于哪个集合。
- 合并：合并两个集合。
- 添加：添加一个元素作为一个新集合的元素。

## 复杂度

不加任何优化的并查集单次查询时间复杂度为 $O(n)$，经过路径压缩或按秩合并任意一种优化后的单次查询时间复杂度为 $O(\log n)$，如果同时使用两种优化时间复杂度则为 $O(\alpha(n))$。

空间复杂度为 $O(n)$。

## 实现
提供 C++ 编写，同时使用路径压缩和按秩合并优化的版本。

```cpp
/**
* @file disjoint-set-data-structure.cpp
* @breif Disjoint-set data structure.
* @author XYY1411
* @email xyy1411@gmail.com
* @date 2021-12-11
* @license CC BY-NC-SA 4.0
* Compile instruction: g++ Luogu3367.cpp -o Luogu3367 -std=c++14 -Wall
*   -Wextra -fsanitize=address,undefined,bounds-strict -O2
*/
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
template <typename T>
constexpr void qread(T &n) {
    n = 0;
    bool flag = false;
    char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') flag = true, c = getchar();
    while (isdigit(c)) n = (n << 3) + (n << 1) + (c ^ 48), c = getchar();
    n = flag ? -n : n;
}
template <typename T, typename ...Argv>
void qread(T &n, Argv &...argv) {
    qread(n), qread(argv...);
}
constexpr int maxn = 1e4 + 5;
int fa[maxn], size[maxn];
inline void init(int n) {
    for (int i = 1; i <= n; ++i) fa[i] = i, size[i] = 1;
}
inline int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}
inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (size[fx] < size[fy]) swap(fx, fy);
    fa[fy] = fx;
    size[fx] += size[fy];
}
int n, m;
int main() {
    qread(n, m);
    init(n);
    for (int i = 1; i <= m; ++i) {
        static int x, y, z, fx, fy;
        qread(z, x, y);
        if (z == 1) {
            merge(x, y);
        } else if (z == 2) {
            fx = find(x), fy = find(y);
            puts(fx == fy ? "Y" : "N");
        }
    }
    return 0;
}
```

## 参考资料

1. [并查集 - 维基百科](https://zh.wikipedia.org/w/index.php?title=并查集&oldid=64402641)，维基百科，2021 年 2 月 20 日 21 : 51（HKT）。
2. [Disjoint-set data structure - Wikipedia](https://en.wikipedia.org/w/index.php?title=Disjoint-set_data_structure&oldid=1054790861)，Wikipedia，2021 年 11 月 12 日 11 : 28（HKT）。