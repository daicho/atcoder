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
    vi ans(1 << n);
    vector<vector<pair<int, int>>> x(1 << n);

    rep(i, n) {
        x[i] = vector<pair<int, int>>(1 << (n - i));
    }

    rep(i, 1 << n) {
        int a;
        cin >> a;
        x[0][i] = make_pair(i, a);
    }

    rep(i, n - 1) {
        rep(j, 1 << (n - i - 1)) {
            if (x[i][2 * j].second > x[i][2 * j + 1].second) {
                x[i + 1][j] = x[i][2 * j];
                ans[x[i][2 * j + 1].first] = i + 1;
            } else {
                x[i + 1][j] = x[i][2 * j + 1];
                ans[x[i][2 * j].first] = i + 1;
            }
        }
    }

    ans[x[n - 1][0].first] = n;
    ans[x[n - 1][1].first] = n;

    rep(i, 1 << n) {
        cout << ans[i] << endl;
    }

    return 0;
}
