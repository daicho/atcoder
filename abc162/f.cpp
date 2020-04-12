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
    vl a(n);
    rep(i, n) cin >> a[i];

    vl m(n, 0);
    vl f(n, false);
    if (a[0] >= a[1]) {
        m[2] = a[0];
        f[2] = 0;
    }
    else
    {
        m[2] = a[1];
        f[2] = 1;
    }
    
    if (a[2] > m[2]) {
        m[3] = a[2];
        f[3] = 2;
    } else {
        m[3] = m[2];
        f[3] = f[2];
    }

    rep(i, 4, n + 1) {
        if (i % 2) {
            // 奇数
            if (m[i - 1] >= m[i - 1] - a[f[i - 1]] + a[i - 1]) {
                m[i] = m[i - 1];
                f[i] = f[i - 1];
            } else {
                m[i] = m[i - 1] - a[f[i - 1]] + a[i - 1];
                f[i] = i - 1;
            }
        } else {
            // 偶数
            if (f[i - 1] == i - 2) {
                m[i] = m[i - 2] + a[i - 1];
                f[i] = i - 1;
            } else {
                m[i] = m[i - 1] + a[i - 1];
                f[i] = i - 1;
            }
        }
    }

    cout << m[n - 1] << endl;

    return 0;
}
