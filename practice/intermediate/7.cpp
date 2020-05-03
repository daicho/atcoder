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
    vi x(n), y(n);
    vvb m(5001, vb(5001, false));
    rep(i, n) {
        cin >> x[i] >> y[i];
        m[x[i]][y[i]] = true;
    }

    int s = 0;

    rep(i, n - 1) {
        rep(j, i + 1, n) {
            int rx = y[i] - y[j];
            int ry = x[j] - x[i];
            if (0 <= x[i] + rx && x[i] + rx <= 5000 && 0 <= y[i] + ry && y[i] + ry <= 5000 &&
                0 <= x[j] + rx && x[j] + rx <= 5000 && 0 <= y[j] + ry && y[j] + ry <= 5000) {
                if (m[x[i] + rx][y[i] + ry] && m[x[j] + rx][y[j] + ry])
                    umax(s, rx * rx + ry * ry);
            }

            if (0 <= x[i] - rx && x[i] - rx <= 5000 && 0 <= y[i] - ry && y[i] - ry <= 5000 &&
                0 <= x[j] - rx && x[j] - rx <= 5000 && 0 <= y[j] - ry && y[j] - ry <= 5000) {
                if (m[x[i] - rx][y[i] - ry] && m[x[j] - rx][y[j] - ry])
                    umax(s, rx * rx + ry * ry);
            }
        }
    }

    cout << s << endl;

    return 0;
}
