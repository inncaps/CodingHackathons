#include <bits/stdc++.h>

using namespace std;
              
const int N = 12345;

char s[N];
int c[N];
int a[N];
int b[N];
int len;
int ans;
int fact[N];

void dfs(int v, int s1, int s2) {
  if (v == len) {
    if (s1 == 0) {
      return;
    }
    int coeff = 1;
    if (s2 > len) {
      int c0 = len;
      for (int i = 0; i < len; i++) {
        c0 -= c[i];
      }
      coeff = fact[len];
      for (int i = 0; i < len; i++) {
        coeff /= fact[c[i]];
      }
      coeff /= fact[c0];
      coeff++;
    }
    for (int i = 0; i < len; i++) {
      a[i] = c[i];
    }
    while (true) {
      bool eqs = true;
      for (int i = 0; i < len; i++) {
        if (a[i] != s[i] - '0') {
          eqs = false;
          break;
        }
      }
      if (eqs) {
        ans += coeff;
        break;
      }
      for (int i = 0; i < len; i++) {
        b[i] = 0;
      }
      for (int i = 0; i < len; i++) {
        if (a[i] != 0) {
          b[a[i] - 1]++;
        }
      }
      eqs = true;
      for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
          eqs = false;
          break;
        }
      }
      if (eqs) {
        break;
      }
      for (int i = 0; i < len; i++) {
        a[i] = b[i];
      }
    }
    return;
  }
  for (int d = 0; d <= len; d++) {
    if (s1 + d <= len) {
      c[v] = d;
      dfs(v + 1, s1 + d, s2 + d * (v + 1));
    }
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    scanf("%s", s);
    len = strlen(s);
    fact[0] = 1;
    for (int i = 1; i <= len; i++) {
      fact[i] = fact[i - 1] * i;
    }
    int s1 = 0;
    for (int i = 0; i < len; i++) {
      s1 += (s[i] - '0');
    }
    if (s1 > len) {
      printf("%d\n", 1);
      continue;
    }
    ans = 0;
    dfs(0, 0, 0);
    printf("%d\n", ans);
  }
  return 0;
}