#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n, p;
        cin >> n >> p;
        vector<int> v(p);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++v[a % p];
        }
        int ans = v[0] + 1;
        if (p == 2) {
            ans += v[1] / 2;
            v[1] = v[1] % 2;
            if (v[1] == 0) {
                --ans;
            }
        } else if (p == 3) {
            int temp = min(v[1], v[2]);
            v[1] -= temp;
            v[2] -= temp;
            ans += temp;
            ans += v[1] / 3;
            ans += v[2] / 3;
            v[1] = v[1] % 3;
            v[2] = v[2] % 3;
            if (v[1] + v[2] == 0) {
                --ans;
            }
        } else {
            ans += v[2] / 2;
            int temp = min(v[1], v[3]);
            v[1] -= temp;
            v[3] -= temp;
            ans += temp;
            ans += v[1] / 4;
            ans += v[3] / 4;
            v[2] = v[2] % 2;
            v[1] = v[1] % 4;
            v[3] = v[3] % 4;
            if (v[1] + v[2] + v[3] == 0) {
                --ans;
            }
        }

        cout << "Case #" << test << ": " << ans << std::endl;
    }
    return 0;
}
