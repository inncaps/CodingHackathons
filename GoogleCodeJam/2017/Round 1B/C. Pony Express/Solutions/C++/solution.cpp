#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef pair<int, int> PII;

const int N = 105;

double ti[N][N], km[N], g[N][N], sp[N];
const double inf = (double) 1e19;

int main() {
  int T, n, q;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
      cin >> km[i] >> sp[i];
    }
    int d, u, v;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> d;
        g[i][j] = d == -1 ? inf : (double) d;
        ti[i][j] = inf;
      }
      ti[i][i] = g[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j && g[i][j] <= km[i]) {
          ti[i][j] = g[i][j] / sp[i];
        }
      }
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          ti[i][j] = min(ti[i][j], ti[i][k] + ti[k][j]);
        }
      }
    }
    while (q--) {
      cin >> u >> v;
      cout << fixed << setprecision(10) << ti[u - 1][v - 1] << " ";
    }
    cout << "\n";
  }
  return 0;
}