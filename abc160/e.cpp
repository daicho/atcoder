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
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<ll> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];

    sort(rrng(p));
    sort(rrng(q));
    sort(rrng(r));

    ll P = x - 1;
    ll Q = y - 1;
    ll R = 0;

    rep(i, c) {
        if (P >= 0 && Q >= 0) {
            if (p[P] < q[Q]) {
                if (p[P] < r[R]) {
                    p[P] = r[R];
                    P--;
                    R++;
                } else {
                    break;
                }
            } else {
                if (q[Q] < r[R]) {
                    q[Q] = r[R];
                    Q--;
                    R++;
                } else {
                    break;
                }
            }
        } else {
            if (P >= 0) {
                if (p[P] < r[R]) {
                    p[P] = r[R];
                    P--;
                    R++;
                } else {
                    break;
                }
            } else if (Q >= 0) {
                if (q[Q] < r[R]) {
                    q[Q] = r[R];
                    Q--;
                    R++;
                } else {
                    break;
                }
            }
        }
    }

    ll sum = 0;

    rep(i, x)
        sum += p[i];

    rep(i, y)
        sum += q[i];

    cout << sum << endl;

    return 0;
}
