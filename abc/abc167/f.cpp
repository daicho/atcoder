#include <bits/stdc++.h>

#define __sel(_1, _2, x, ...) x

#define repn(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, ...) __sel(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (ll i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (ll i = (b - 1); i >= (a); i--)
#define rrep(i, ...) __sel(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define umax(m, x) (m = max(m, x))
#define umin(m, x) (m = min(m, x))
#define rng(v) v.begin(), v.end()
#define rrng(v) v.rbegin(), v.rend()
#define bit(x, n) ((x) >> (n) & 1)

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define pt(x) cout << (x) << endl;
#define ptv(v) for (auto __t1 : v) cout << __t1 << " "; cout << endl;
#define ptl(v) for (auto __t1 : v) cout << __t1 << endl;
#define shv(v) for (auto __t1 : v) cerr << __t1 << " "; cerr << endl;
#define db(x) cerr << #x << ": " << (x) << endl;
#define dbv(v) cerr << #v << ": "; shv(v);
#define dbm(m) cerr << #m << ":" << endl; for (auto __t2 : m) { shv(__t2); }

using namespace std;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vld = vector<ld>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vpii = vector<pii>;
using vpll = vector<pll>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvd = vector<vector<double>>;
using vvld = vector<vector<ld>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;

inline int gi() { int x; cin >> x; return x; }
inline ll gl() { int x; cin >> x; return x; }
inline char gc() { char x; cin >> x; return x; }
inline string gs() { string x; cin >> x; return x; }
inline int ni() { return gi() - 1; }
inline ll nl() { return gl() - 1; }

inline vi gvi(int n) { vi v; rep(i, n) v.pb(gi()); return v; }
inline vl gvl(int n) { vl v; rep(i, n) v.pb(gl()); return v; }
inline vc gvc(int n) { vc v; rep(i, n) v.pb(gc()); return v; }
inline vs gvs(int n) { vs v; rep(i, n) v.pb(gs()); return v; }
inline vi nvi(int n) { vi v; rep(i, n) v.pb(ni()); return v; }
inline vl nvl(int n) { vl v; rep(i, n) v.pb(nl()); return v; }

inline vvi gvvi(int m, int n) { vvi v; rep(i, n) v.pb(gvi(m)); return v; }
inline vvl gvvl(int m, int n) { vvl v; rep(i, n) v.pb(gvl(m)); return v; }
inline vvc gvvc(int m, int n) { vvc v; rep(i, n) v.pb(gvc(m)); return v; }
inline vvs gvvs(int m, int n) { vvs v; rep(i, n) v.pb(gvs(m)); return v; }
inline vvi nvvi(int m, int n) { vvi v; rep(i, n) v.pb(nvi(m)); return v; }
inline vvl nvvl(int m, int n) { vvl v; rep(i, n) v.pb(nvl(m)); return v; }

inline void yn(bool f) { cout << (f ? "Yes" : "No") << endl; }


int main() {
    ll n = gl();
    ll sum = 0;
    bool fl = false;
    bool fr = false;
    bool f = false;

    rep(i, n) {
        string s;
        cin >> s;
        sum -= (ll)s.length();
        for (auto& c : s)
            if (c == '(') sum += 2;

        if (s[0] == '(' && fr) f = true;
        if (s[(int)s.length() - 1] == ')' && fl) f = true;
        if (s[0] == '(') fl = true;
        if (s[(int)s.length() - 1] == ')') fr = true;
    }
    yn ((n == 1 && fl && fr) || (n >= 2 && f && sum == 0));

    return 0;
}
