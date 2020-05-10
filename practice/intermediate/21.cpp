#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (ll i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (ll i = (b - 1); i >= (a); i--)
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
    ll n;
    cin >> n;
    vl h(n), s(n);
    rep(i, n) cin >> h[i] >> s[i];

    ll left = 1, right = 1e14 + 1e9;

    while (right - left > 1) {
        ll half = (left + right) / 2;

        // 高度half以内に落とすには、何秒以内に打てばいいか
        vl time(n);
        rep(i, n) {
            if (h[i] > half) time[i] = -1;
            else time[i] = (half - h[i]) / s[i];
        }
        sort(rng(time));

        // 高度half以内に全ての風船を落とすのは可能か
        bool f = true;
        rep(i, n) {
            if (time[i] < i) {
                f = false;
                break;
            }
        }

        if (f)
            right = half;
        else
            left = half;
    }

    cout << right << endl;

    return 0;
}
