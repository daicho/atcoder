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


void dfs(vvi& g, vi& cnt, int p, vi& ans) {
    for (auto t : g[p]) {
        if (ans[t] != -1) continue;
        ans[t] = ans[p] + cnt[t];
        dfs(g, cnt, t, ans);
    }
}

int main() {
    int n = gi(), q = gi();
    vi cnt(n, 0);
    vvi g(n);
    rep(i, 1, n) {
        int a = gi(), b = gi();
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    rep(i, q) {
        int p = gi(), x = gi();
        cnt[p - 1] += x;
    }
    vi ans(n, -1);
    ans[0] = cnt[0];
    dfs(g, cnt, 0, ans);
    for (auto t : ans)
        cout << t << " ";
    cout << endl;

    return 0;
}
