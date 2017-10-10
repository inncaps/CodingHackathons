#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int de[N];
vector < pair <int, int> > g[N];
int _ans[2 * N], *ans = _ans + N;
int from[N], to[N];
vector < pair <int, int> > st;

void dfs(int v, int pr) {
  for (auto &p : g[v]) {
    int u = p.first;
    int id = p.second;
    if (id == ~pr) {
      continue;
    }
    if (de[u] == -1) {
      de[u] = de[v] + 1;
      st.emplace_back(u, id);
      dfs(u, id);
      st.pop_back();
      continue;
    }
    if (de[u] < de[v]) {
      ans[id]++;
      for (int i = (int) st.size() - 1; i >= 0; i--) {
        if (st[i].first == u) {
          break;
        }
        ans[st[i].second]++;
      }
    }
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d:", qq);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
    for (int i = 0; i < m; i++) {
      scanf("%d %d", from + i, to + i);
      from[i]--; to[i]--;
      g[from[i]].emplace_back(to[i], i);
      g[to[i]].emplace_back(from[i], ~i);
      ans[i] = ans[~i] = 0;
    }
    for (int i = 0; i < n; i++) {
      de[i] = -1;
    }
    for (int i = 0; i < n; i++) {
      if (de[i] != -1) {
        continue;
      }
      de[i] = 0;
      st.clear();
      st.emplace_back(i, -1);
      dfs(i, -1);
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
      ans[i] -= ans[~i];
      if (ans[i] == 0) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      puts(" IMPOSSIBLE");
    } else {
      for (int i = 0; i < m; i++) {
        printf(" %d", ans[i]);
      }
      printf("\n");
    }
  }
  return 0;
}