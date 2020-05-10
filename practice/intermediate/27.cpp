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

inline vi gvi(int n) { vi v(n); rep(i, n) cin >> v[i]; return v; }
inline vl gvl(int n) { vl v(n); rep(i, n) cin >> v[i]; return v; }
inline vc gvc(int n) { vc v(n); rep(i, n) cin >> v[i]; return v; }
inline vs gvs(int n) { vs v(n); rep(i, n) cin >> v[i]; return v; }

inline vvi gvvi(int h, int w) { vvi m(h, vi(w)); rep(i, h) rep(j, w) cin >> m[i][j]; return m; }
inline vvl gvvl(int h, int w) { vvl m(h, vl(w)); rep(i, h) rep(j, w) cin >> m[i][j]; return m; }
inline vvc gvvc(int h, int w) { vvc m(h, vc(w)); rep(i, h) rep(j, w) cin >> m[i][j]; return m; }
inline vvs gvvs(int h, int w) { vvs m(h, vs(w)); rep(i, h) rep(j, w) cin >> m[i][j]; return m; }

inline void yn(bool f) { cout << (f ? "Yes" : "No") << endl; }


int m, n;

int dfs(vvi& v, int x, int y, vvb& e) {
    e[y][x] = true;
    int ret = 0;
    rep(i, -1, 2) {
        rep(j, -1, 2) {
            if ((i && j) || (!i && !j)) continue;
            if (v[y + i][x + j] && !e[y + i][x + j])
                umax(ret, dfs(v, x + j, y + i, e));
        }
    }
    e[y][x] = false;
    return ret + 1;
}

int main() {
    m = gi(), n = gi();
    vvi v(n + 2, vi(m + 2, 0));
    rep(i, 1, n + 1) rep(j, 1, m + 1)
        cin >> v[i][j];
    dbm(v);

    int ans = 0;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            vvb e(n + 2, vb(m + 2, false));
            if (v[i][j])
                umax(ans, dfs(v, j, i, e));
        }
    }

    pt(ans);

    return 0;
}
