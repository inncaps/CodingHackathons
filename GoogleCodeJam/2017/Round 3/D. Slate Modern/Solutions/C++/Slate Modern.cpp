#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long) 9e18;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

const int N = 1234567;

int x[N], y[N], v[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int r, c, n, d;
    scanf("%d %d %d %d", &r, &c, &n, &d);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", x + i, y + i, v + i);
      x[i]--; y[i]--;
    }
    int ans = 0;
    bool ok = true;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        long long z = inf;
        long long must = -1;
        for (int k = 0; k < n; k++) {
          int dist = abs(i - x[k]) + abs(j - y[k]);
          z = min(z, v[k] + (long long) d * dist);
          if (dist == 0) {
            must = v[k];
          }
        }
        if (must != -1 && must != z) {
          ok = false;
        }
        add(ans, z % md);
      }
    }
    if (!ok) {
      puts("IMPOSSIBLE");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}