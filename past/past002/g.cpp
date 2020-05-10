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
    ll q;
    cin >> q;

    vector<pair<char, ll>> s;
    ll p = 0;
    ll o = 0;

    rep(i, q) {
        int t;
        cin >> t;

        if (t == 1) {
            char c;
            ll x;
            cin >> c >> x;
            s.push_back(make_pair(c, x));
        } else {
            ll d;
            cin >> d;

            vl del(26, 0);
            while (p < s.size()) {
                if (s[p].second - o <= d) {
                    del[s[p].first - 'a'] += s[p].second - o;
                    d -= (s[p].second - o);
                    p++;
                    o = 0;
                } else {
                    del[s[p].first - 'a'] += d;
                    o += d;
                    break;
                }
            }

            ll sum = 0;
            rep(j, 26) {
                // if (del[i]) cout << char(i + 'a') << " : " << del[i] << endl;
                sum += del[j] * del[j];
            }
            cout << sum << endl;
        }

        // cout << "s = ";
        // rep(j, p, s.size()) {


        // }
    }

    return 0;
}
