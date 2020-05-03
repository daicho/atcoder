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
    int n, m;
    cin >> n >> m;

    vi x(m), y(m);
    vvi f(n);
    rep(i, m) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        f[x[i]].push_back(y[i]);
        f[y[i]].push_back(x[i]);
    }

    int ans = 0;

    rep(i, n) {
        bool flag = true;

        rep(j, f[i].size()) {
            int cnt = 0;
            rep(k, f[f[i][j]].size()) {
                if (f[f[i][j]][k] == j)
                    cnt++;

                rep(l, f[i].size()) {
                    if (f[i][l] == f[f[i][j]][k]) {
                        cnt++;
                        break;
                    }
                }
            }

            if (cnt < f[i].size()) {
                flag = false;
                break;
            }
        }

        if (flag) {
            umax(ans, int(f[i].size() + 1));
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
