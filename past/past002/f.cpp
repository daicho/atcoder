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
    ll n;
    cin >> n;

    vl a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i], a[i]--, b[i]--;
    vvl t(n);
    rep(i, n) {
        t[a[i]].push_back(b[i]);
    }

    vvl x(n, vl(100, 0));
    for (auto tt : t[0])
        x[0][tt]++;

    rep(i, 1, n) {
        rep(j, 100)
            x[i][j] = x[i - 1][j];

        for (auto tt : t[i])
            x[i][tt]++;
    }

    vl d(100, 0);
    ll sum = 0;

    rep(i, n) {
        rrep(j, 100) {
            if (x[i][j] - d[j] > 0) {
                sum += j + 1;
                d[j]++;
                cout << sum << endl;
                break;
            }
        }
    }

    return 0;
}
