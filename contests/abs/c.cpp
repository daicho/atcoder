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
    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    int cnt = 0;

    while (true) {
        bool f = true;

        rep(i, n) {
            if (a[i] % 2) {
                f = false;
                break;
            }
        }

        if (f) {
            rep(i, n) {
                a[i] /= 2;
            }

            cnt++;
        } else {
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}
