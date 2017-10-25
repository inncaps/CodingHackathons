#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double ld;
typedef long double ll;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int tests;
    cin >> tests;
    cout << fixed << setprecision(20);
    for (int test = 1; test <= tests; ++test) {
        int n, q;
        cin >> n >> q;
        vector<pair<ll, ll>> horses(n);
        for (int i = 0; i < n; ++i) {
            cin >> horses[i].first >> horses[i].second;
        }
        vector<vector<ll>> americmap(n, vector<ll>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> americmap[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            americmap[i][i] = 0;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (americmap[i][k] != -1 &&
                        americmap[k][j] != -1) {
                        if (americmap[i][j] != -1) {
                            americmap[i][j] = min(americmap[i][j],
                                                  americmap[i][k] +
                                                  americmap[k][j]);
                        } else {
                            americmap[i][j] = americmap[i][k] + americmap[k][j];
                        }
                    }
                }
            }
        }
        vector<vector<ld>> upgradedmap(n, vector<ld>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (americmap[i][j] != -1 &&
                    americmap[i][j] <= horses[i].first) {
                    upgradedmap[i][j] = americmap[i][j];
                    upgradedmap[i][j] /= horses[i].second;
                } else {
                    upgradedmap[i][j] = -100;
                }
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (upgradedmap[i][k] > -1 &&
                        upgradedmap[k][j] > -1) {
                        if (upgradedmap[i][j] > -1) {
                            upgradedmap[i][j] = min(upgradedmap[i][j],
                                                    upgradedmap[i][k] +
                                                    upgradedmap[k][j]);
                        } else {
                            upgradedmap[i][j] =
                                upgradedmap[i][k] + upgradedmap[k][j];
                        }
                    }
                }
            }
        }
        cout << "Case #" << test << ":";
        while (q-- > 0) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            cout << " " << upgradedmap[a][b];
        }
        cout << endl;
    }
    return 0;
}
