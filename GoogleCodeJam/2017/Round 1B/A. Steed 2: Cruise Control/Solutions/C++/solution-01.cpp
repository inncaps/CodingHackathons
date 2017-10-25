#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int tests;
    cin >> tests;
    cout << fixed << setprecision(15);
    for (int test = 1; test <= tests; ++test) {
        double d, n;
        cin >> d >> n;
        double a, b;
        cin >> a >> b;
        double answer = d / ((d - a) / b);
        for (int i = 1; i < n; ++i) {
            cin >> a >> b;
            answer = min(answer, d / ((d - a) / b));
        }
        std::cout << "Case #" << test << ": " << answer << endl;
    }
    return 0;
}
