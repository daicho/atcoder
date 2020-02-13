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
    int N, W;
    cin >> N >> W;

    vector<ll> w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(100001, LINF));

    dp[0][0] = 0;

    rep(i, N) rep(j, 100001) {
        if (j - v[i] >= 0)
            dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
        else
            dp[i + 1][j] = dp[i][j];
    }

    rrep(i, 100001) {
        if (dp[N][i] <= W) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
