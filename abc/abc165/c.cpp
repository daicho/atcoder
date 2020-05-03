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
    int n, m, q;
    cin >> n >> m >> q;

    vi a(q), b(q), c(q), d(q);
    rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    ll ans = 0;
    vi A(n, 1);
    while (true) {
        ll sum = 0;
        rep(i, q) {
            if (A[b[i] - 1] - A[a[i] - 1] == c[i])
                sum += d[i];
        }
        umax(ans, sum);

        rrep(i, n) {
            if (A[i] < m) {
                A[i]++;
                int t = A[i];
                rep(j, i + 1, n)
                    A[j] = t;
                break;
            }
            if (i == 0) {
                cout << ans << endl;
                return 0;
            }
        }
    }

    return 0;
}
