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

using ll = long long int;

using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;

const int INF = 1e9;
const ll LINF = 1e18;

inline void yn(bool f) { cout << (f ? "Yes" : "No") << endl; }


int main() {
    int n;
    cin >> n;
    vl a(n), b(n);
    vl p;
    rep(i, n) {
        cin >> a[i] >> b[i];
        p.push_back(a[i]);
        p.push_back(b[i]);
    }

    ll ans = LINF;
    rep(i, p.size()) {
        rep(j, i, p.size()) {
            ll dist = 0;
            rep(k, n) {
                dist += min(abs(p[i] - a[k]) + b[k] - a[k] + abs(p[j] - b[k]),
                            abs(p[i] - b[k]) + b[k] - a[k] + abs(p[j] - a[k]));
            }
            umin(ans, dist);
        }
    }

    cout << ans << endl;

    return 0;
}
