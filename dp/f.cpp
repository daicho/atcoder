#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (int i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (int i = (b - 1); i >= (a); i--)
#define rrep(i, ...) select(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define all(v) v.begin(), v.end()
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;


int main() {
    string s, t;
    cin >> s >> t;

    vector<vector<string>> dp(s.length() + 1, vector<string>(t.length() + 1, ""));

    rep(i, 0, s.length()) rep(j, 0, t.length()) {
        if (s[i] == t[j])
            dp[i + 1][j + 1] = dp[i][j] + s[i];
        else {
            if (dp[i][j + 1].length() > dp[i + 1][j].length())
                dp[i + 1][j + 1] = dp[i][j + 1];
            else
                dp[i + 1][j + 1] = dp[i + 1][j];
        }
    }

    // rep(i, s.length() + 1) {
    //     rep(j, t.length() + 1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[s.length()][t.length()] << endl;

    return 0;
}
