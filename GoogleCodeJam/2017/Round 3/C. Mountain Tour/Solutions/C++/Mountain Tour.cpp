#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int to[N], ta[N], tb[N];
vector <int> inc[N];
int cost[N];
int a[N], b[N];
int p[N];
int out[N], comp[N];
vector < pair < int, pair <int, int> > > edges;

int find_set(int x) {
  if (x != p[x]) {
    p[x] = find_set(p[x]);
  }
  return p[x];
}

int match(int j, int i) {
  int wait = ((ta[j] - (ta[i] + tb[i])) % 24 + 24) % 24;
  return wait;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      inc[i].clear();
    }
    for (int i = 0; i < 2 * n; i++) {
      scanf("%d %d %d", to + i, ta + i, tb + i);
      to[i]--;
    }
    int res = (int) 1e9;
    for (int rot = 0; rot < 2; rot++) {
      swap(to[0], to[1]);
      swap(ta[0], ta[1]);
      swap(tb[0], tb[1]);
      for (int i = 0; i < n; i++) {
        inc[i].clear();
      }
      for (int i = 0; i < 2 * n; i++) {
        inc[to[i]].push_back(i);
      }
      int ans = ta[0];
      for (int i = 0; i < 2 * n; i++) {
        ans += tb[i];
      }
      for (int i = 0; i < n; i++) {
        if (i != 0) {
          int x = match(2 * i, inc[i][0]) + match(2 * i + 1, inc[i][1]);
          int y = match(2 * i, inc[i][1]) + match(2 * i + 1, inc[i][0]);
          if (x > y) {
            swap(x, y);
            swap(inc[i][0], inc[i][1]);
          }
          cost[i] = y - x;
          ans += x;
        } else {
          int x = match(2 * i + 1, inc[i][1]);
          int y = match(2 * i + 1, inc[i][0]);
          if (x > y) {
            swap(x, y);
            swap(inc[i][0], inc[i][1]);
          }
          cost[i] = y - x;
          ans += x;
        }
      }
      for (int i = 0; i < 2 * n; i++) {
        a[i] = i;
      }
      for (int i = 0; i < n; i++) {
        b[inc[i][0]] = 2 * i;
        b[inc[i][1]] = 2 * i + 1;
      }
      for (int i = 0; i < 2 * n; i++) {
        out[a[i]] = b[i];
      }
      for (int i = 0; i < 2 * n; i++) {
        comp[i] = -1;
      }
      int nc = 0;
      for (int i = 0; i < 2 * n; i++) {
        if (comp[i] != -1) {
          continue;
        }
        int p = i;
        while (comp[p] == -1) {
          comp[p] = nc;
          p = out[p];
        }
        nc++;
      }
      edges.clear();
      for (int i = 0; i < n; i++) {
        int x = comp[2 * i];
        int y = comp[2 * i + 1];
        if (x != y) {
          edges.push_back(make_pair(cost[i], make_pair(x, y)));
        }
      }
      sort(edges.begin(), edges.end());
      for (int i = 0; i < nc; i++) {
        p[i] = i;
      }
      for (auto &e : edges) {
        int x = find_set(e.second.first);
        int y = find_set(e.second.second);
        if (x != y) {
          ans += e.first;
          p[x] = y;
        }
      }
      for (int i = 0; i < nc; i++) {
        assert(find_set(i) == find_set(0));
      }
      res = min(res, ans);
    }
    printf("%d\n", res);
  }
  return 0;
}