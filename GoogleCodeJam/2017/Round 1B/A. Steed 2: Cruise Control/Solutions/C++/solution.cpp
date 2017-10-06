#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef pair<int, int> PII;

const int N = 300004;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    double d, k, s, ans = (double) 2e18;
    int n;
    cin >> d >> n;
    while (n--) {
      cin >> k >> s;
      ans = min(ans, d * s / (d - k));
    }
    cout << fixed << setprecision(10) << ans << "\n";
  }
  return 0;
}