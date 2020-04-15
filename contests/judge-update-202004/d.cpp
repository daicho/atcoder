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
using vs = vector<string>;
using vb = vector<bool>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvb = vector<vector<bool>>;

const int INF = 1e9;
const ll LINF = 1e18;

inline void yn(bool f) { cout << (f ? "Yes" : "No") << endl; }


int main() {
    int n, q;
    cin >> n >> q;

    vi a(n), s(q);
    rep(i, n) cin >> a[i];
    rep(i, q) cin >> s[i];

    vi k(n);
    k[0] = a[0];
    rep(i, 1, n)
        k[i] = gcd(k[i - 1], a[i]);

    rep(i, q) {
        bool f = true;
        rep(j, n) {
            if (gcd(k[j], s[i]) == 1) {
                cout << j + 1 << endl;
                f = false;
                break;
            }
        }
        if (f) {
            cout << k.back() << endl;
        }
    }

    return 0;
}
