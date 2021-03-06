#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (int i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (int i = (b - 1); i >= (a); i--)
#define rrep(i, ...) select(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define all(v) v.begin(), v.end()
#define debug(x) std::cerr << #x << " = " << x << std::endl

using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<int> dp(n);

    rep(i, 1, n) {
        dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
        rrepr(j, i - k, i - 1) {
            if (j < 0) break;
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}
