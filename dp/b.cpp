#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (int i = (b - 1); i >= (a); i--)

#define all(v) (v).begin(), (v).end();
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<int> dp(n);

    repr(i, 1, n) {
        dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
        rrepr(j, i - k, i - 1) {
            if (j < 0) break;
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}
