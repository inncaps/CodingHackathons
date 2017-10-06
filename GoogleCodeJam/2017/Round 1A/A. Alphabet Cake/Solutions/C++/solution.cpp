#include <bits/stdc++.h>
using namespace std;
string s[423];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, tt = 0;
    cin >> t;
    while (t--) {
        cout << "Case #" << ++tt << ":\n";
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '?') {
                    continue;
                }
                // send up and down
                for (int k = i - 1; k >= 0; --k) {
                    if (s[k][j] == '?') {
                        s[k][j] = s[i][j];
                    }
                    else {
                        break;
                    }
                }
                for (int k = i + 1; k < n; ++k) {
                    if (s[k][j] == '?') {
                        s[k][j] = s[i][j];
                    }
                    else {
                        break;
                    }
                }    
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '?') {
                    continue;
                }
                // send left and right
                for (int k = j - 1; k >= 0; --k) {
                    if (s[i][k] == '?') {
                        s[i][k] = s[i][j];
                    }
                    else {
                        break;
                    }
                }
                for (int k = j + 1; k < m; ++k) {
                    if (s[i][k] == '?') {
                        s[i][k] = s[i][j];
                    }
                    else {
                        break;
                    }
                }    
            }
        }
        for (int i = 0; i < n; ++i ) {
            cout << s[i] << endl;
        }
    } 
}   