#include <bits/stdc++.h>
using namespace std;
int required[1000];
int available[55][55]; 
int pos[55];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, tt = 0;
    cin >> t;
    while (t--) {
        cout << "Case #" << ++tt << ": ";
        int n, p;
        cin >> n >> p;
        for (int i = 0; i < n; ++i) {
            cin >> required[i];
        }        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < p; ++j) {
                cin >> available[i][j];
            }
            sort(available[i], available[i] + p);
        }
        for (int i = 0; i < n; ++i) {
            pos[i] = 0;
            for (int j = 0; j < p; ++j) {
                if (available[i][j] * 100 < required[i] * 90) {
                    ++pos[i];
                }
                else {
                    break;
                }
            }
        }
        int ans = 0;
        int low[55], high[55];
        while (true) {
            bool done = false;
            for (int i = 0; i < n; ++i) {
                if (pos[i] == p) {
                    done = true;
                }
            }
            if (done) {
                break;
            }
            int limitingHigh = 0;
            int minHigh = 1e9;
            int maxLow = -1;
            for (int i = 0; i < n; ++i) {
                low[i] = (100 * available[i][pos[i]] + 110 * required[i] - 1) / (110 * required[i]);
                high[i] = (100 * available[i][pos[i]]) / (90 * required[i]);
                if (high[i] < high[limitingHigh]) {
                    limitingHigh = i;
                }
                minHigh = min(minHigh, high[i]);
                maxLow = max(maxLow, low[i]);
            }
            if (minHigh == 0 or minHigh < maxLow) {
                ++pos[limitingHigh];
            }
            else {
                ++ans;
                for (int i = 0; i < n; ++i) {
                    ++pos[i];
                }
            }
        }
        cout << ans << endl;
    } 
}   