#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int hd, ad, hk, ak, b, d;
int play(int dc, int bc) {
    int myHealth = hd;
    int hisHealth = hk;
    int myAttack = ad;
    int hisAttack = ak;
    int turn = 0;
    int ans = 0;
    int moves = 1000;

    while (moves--) {
        ++turn;
        // cout << turn << endl;
        // cout << "Me: " << myAttack << " " << myHealth << endl;
        // cout << "He: " << hisAttack << " " << hisHealth << endl;
        // my turn
        if (turn & 1) {
            ++ans;
            if (dc > 0) {
                // can I survive his next attack if i reduce him right now?
                if (myHealth - max(0, hisAttack - d) > 0) {
                    hisAttack = max(0, hisAttack - d);
                    --dc;    
                }
                // else heal up
                else {
                    myHealth = hd;
                }
            }
            else if (bc > 0) {
                // can I survive his next attack?
                if (myHealth - hisAttack > 0) {
                    myAttack = myAttack + b;
                    --bc;    
                }
                // else heal up
                else {
                    myHealth = hd;
                }
            }
            else {
                // can i kill him right now?
                if (hisHealth - myAttack <= 0) {
                    return ans;
                }
                else {
                    // can i survive his next attack? 
                    if (myHealth - hisAttack > 0) {
                        hisHealth -= myAttack;
                    }    
                    else {
                        myHealth = hd;
                    }
                }
            }
        }
        else {
            myHealth -= hisAttack;
            if (myHealth <= 0) {
                return INF;
            }
        }
    }
    return INF;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, tt = 0;
    cin >> t;
    while (t--) {
        cout << "Case #" << ++tt << ": ";
        cin >> hd >> ad >> hk >> ak >> b >> d;
        int ans;
        int MAXD;
        int MAXB;
        if (d == 0) {
            MAXD = 0;
        }
        else {
            MAXD = (ak + d - 1) / d;
        }
        if (b == 0) {
            MAXB = 0;
        }
        else {
            MAXB = (hk + b - 1) / b;
        }
        ans = INF;
        for (int ds = 0; ds <= MAXD; ++ds) {
            for (int bs = 0; bs <= MAXB; ++bs) {
                ans = min(ans, play(ds, bs));
            }
        }    
        if (ans == INF) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout << ans << endl;
        }
    } 
}   