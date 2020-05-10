#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (int i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (int i = (b - 1); i >= (a); i--)
#define rrep(i, ...) select(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define umax(m, x) if (x > m) m = x;
#define umin(m, x) if (x < m) m = x;

#define all(v) v.begin(), v.end()
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;


int main() {
    int n;
    cin >> n;

    vector<vector<ll>> a(n - 1, vector<ll>(n));

    rep(i, n - 1) {
        rep(j, i + 1, n) {
            cin >> a[i][j];
        }
    }

    vector<int> d(n, 0);
    ll max = -LINF;

    while (true) {
        ll sum = 0;
        rep(i, n - 1) {
            rep(j, i + 1, n) {
                if (d[i] == d[j])
                    sum += a[i][j];
            }
        }

        umax(max, sum);

        d[0]++;
        rep(i, n - 1) {
            if (d[i] >= 3) {
                d[i] = 0;
                d[i + 1]++;
            }
        }

        if (d[n - 1] >= 3)
            break;
    }

    cout << max << endl;

    return 0;
}
