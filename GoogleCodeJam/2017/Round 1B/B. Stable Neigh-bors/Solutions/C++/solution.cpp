#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef pair<int, int> PII;

const int N = 300004;

string solve(int r, int y, int b) {
  int n = r + y + b;
  if (max({y, r, b}) * 2 > n) return "IMPOSSIBLE";
  vector<pair<int, char> > P;
  P.push_back({r, 'R'});
  P.push_back({y, 'Y'});
  P.push_back({b, 'B'});
  string s = "#";

  while (n--) {
    sort(P.begin(), P.end(), [&P](pair<int, char> x, pair<int, char> y) {
      return x > y;
    });
    if (P[0].second != s.back()) {
      s += P[0].second;
      P[0].first--;
    } else {
      s += P[1].second;
      P[1].first--;
    }
  }
  n = s.size();
  if (s.size() > 3 && s[1] == s.back()) {
    swap(s[n - 1], s[n - 2]);
  }
  return s.substr(1);
}

bool quit(int x, int y) {
  return (x > 0 && y <= x);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    int n, o, y, g, r, b, v;
    cin >> n >> r >> o >> y >> g >> b >> v;
    if (o + b == n && o == b) {
      while (o--) {
        cout << "OB";
      }
      puts("");
      continue;
    }
    if (r + g == n && r == g) {
      while (r--) {
        cout << "RG";
      }
      puts("");
      continue;
    }
    if (y + v == n && y == v) {
      while (v--) {
        cout << "YV";
      }
      puts("");
      continue;
    }
    if (quit(o, b) || quit(g, r) || quit(v, y)) {
      puts("IMPOSSIBLE");
    } else {
      string ans = solve(r - g, y - v, b - o);
      int k = ans.size();
      if (ans == "IMPOSSIBLE") {
        cout << ans << "\n";
      } else {
        for (int i = k - 1; i >= 0; --i) {
          if (ans[i] == 'B' && o > 0) {
            string rep = "";
            while (o--) rep += "OB";
            ans = ans.substr(0, i + 1) + rep + ans.substr(i + 1);
          }
          if (ans[i] == 'R' && g > 0) {
            string rep = "";
            while (g--) rep += "GR";
            ans = ans.substr(0, i + 1) + rep + ans.substr(i + 1);
          }
          if (ans[i] == 'Y' && v > 0) {
            string rep = "";
            while (v--) rep += "VY";
            ans = ans.substr(0, i + 1) + rep + ans.substr(i + 1);
          }
        }
        cout << ans << "\n";
      }
    }
  }
  return 0;
}