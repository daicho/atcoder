#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (int i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (int i = (b - 1); i >= (a); i--)
#define rrep(i, ...) select(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define umax(m, x) (m = max(m, x))
#define umin(m, x) (m = min(m, x))

#define rng(v) v.begin(), v.end()
#define rrng(v) v.rbegin(), v.rend()

#define bit(x, n) ((x) >> (n) & 1)
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
    int n, m;
    cin >> n >> m;

    vvb f(n, vb(n, false));
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        f[x - 1][y - 1] = true;
    }

    int ans = 0;

    rep(i, 1 << n) {
        bool flag = true;

        rep(j, n - 1) {
            rep(k, j + 1, n) {
                if (bit(i, j) && bit(i, k) && !f[j][k]) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            int cnt = 0;
            rep(j, n) cnt += bit(i, j);
            umax(ans, cnt);
        }
    }

    cout << ans << endl;

    return 0;
}
