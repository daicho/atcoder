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
    int n;
    cin >> n;

    vi x(n);
    vector<char> c(n);
    rep(i, n) cin >> x[i] >> c[i];

    rep(i, n) {
        if (c[i] == 'R') x[i] += 100000;
        else x[i] += 200000;
    }

    sort(rng(x));

    rep(i, n) {
        if (x[i] >= 200000)
            cout << x[i] - 200000 << endl;
        else
            cout << x[i] - 100000 << endl;
    }

    return 0;
}
