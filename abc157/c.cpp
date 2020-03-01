#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (int i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (int i = (b - 1); i >= (a); i--)
#define rrep(i, ...) select(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define all(v) v.begin(), v.end()
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;


int main() {
    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> s(m);
    vector<int> c(m);

    rep(i, m) cin >> s[i] >> c[i];

    vector<int> r(n, -1);

    rep(i, m) {
        if (r[s[i] - 1] == c[i]) {
            ;
        } else if (r[s[i] - 1] != -1) {
            cout << -1 << endl;
            return 0;
        } else {
            r[s[i] - 1] = c[i];
        }
    }

    if (n == 1 && r[0] == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (r[0] == 0) {
        cout << -1 << endl;
        return 0;
    }

    if (r[0] == -1) {
        r[0] = 1;
    }

    rep(i, 1, n) {
        if (r[i] == -1) {
            r[i] = 0;
        }
    }

    rep(i, n) {
        cout << r[i];
    }

    cout << endl;

    return 0;
}
