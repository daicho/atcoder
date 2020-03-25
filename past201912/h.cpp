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
    ll n;
    cin >> n;

    vector<ll> c(n);
    rep(i, n) cin >> c[i];

    ll q;
    cin >> q;

    ll sum = 0;
    ll sub_kisu = 0;
    ll sub_all = 0;

    ll min_kisu = LINF;
    ll min_all = LINF;

    for (int i = 0; i < n; i += 2)
        umin(min_kisu, c[i]);

    rep(i, n)
        umin(min_all, c[i]);

    rep(i, q) {
        char t;
        cin >> t;

        if (t == '1') {
            ll x, a;
            cin >> x >> a;

            if (c[x - 1] >= a + sub_all + ((x % 2) ? sub_kisu : 0)) {
                c[x - 1] -= a;
                sum += a;

                umin(min_all, c[x - 1]);
                if (x % 2)
                    umin(min_kisu, c[x - 1]);
            }
        } else if (t == '2') {
            ll a;
            cin >> a;

            if (min_kisu >= a) {
                sub_kisu += a;
                sum += a * (int)((n + 1) / 2);

                min_kisu -= a;
                umin(min_all, min_kisu);
            }
        } else if (t == '3') {
            ll a;
            cin >> a;

            if (min_all >= a) {
                sub_all += a;
                sum += a * n;

                min_all -= a;
                min_kisu -= a;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
