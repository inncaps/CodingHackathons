#include <bits/stdc++.h>

using namespace std;

const int MAXN = int( 5e2 )+10;

int t,c,n;
int w[ MAXN ], f[ MAXN ];
int dp[ MAXN ][ MAXN ];

int main( ) {

  cin >> t;
  while( t-- ) {
    cin >> c >> n;
    for( int i = 1; i <= n; ++i ) {
      cin >> w[i] >> f[i];
      //Knapsack DP
      for( int j = 0; j <= c; ++j ) {
        dp[i][j] = dp[i-1][j];
        if( j-w[i] >= 0 ) {
          dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+f[i] );
        }
      }
    }
    cout << dp[n][c] << '\n';
  }

  return 0;
}
