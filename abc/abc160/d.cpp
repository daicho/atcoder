#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (int i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (int i = (b - 1); i >= (a); i--)
#define rrep(i, ...) select(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define umax(m, x) (m = max(m, x));
#define umin(m, x) (m = min(m, x));

#define rng(v) v.begin(), v.end()
#define rrng(v) v.rbegin(), v.rend()

#define debug(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;


int main() {
    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> dx(n), dy(n);
    rep(i, n) {
        dx[i] = abs(x - 1 - i);
        dy[i] = abs(y - 1 - i);
    }

    vector<vector<ll>> dist(n, vector<ll>(n));
    vector<ll> ans(n + 1, 0);
    rep(i, n - 1) {
        rep(j, i, n) {
            dist[i][j] = min(min((ll)abs(i - j), dx[i] + dy[j] + 1), dx[j] + dy[i] + 1);
            ans[dist[i][j]]++;
        }
    }

    rep(i, 1, n)
        cout << ans[i] << endl;

    return 0;
}
