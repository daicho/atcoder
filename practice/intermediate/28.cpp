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

inline vvi gvvi(int m, int n) { vvi v(n, vi(m)); rep(i, n) rep(j, m) cin >> v[i][j]; return v; }
inline vvl gvvl(int m, int n) { vvl v(n, vl(m)); rep(i, n) rep(j, m) cin >> v[i][j]; return v; }
inline vvc gvvc(int m, int n) { vvc v(n, vc(m)); rep(i, n) rep(j, m) cin >> v[i][j]; return v; }
inline vvs gvvs(int m, int n) { vvs v(n, vs(m)); rep(i, n) rep(j, m) cin >> v[i][j]; return v; }

inline void yn(bool f) { cout << (f ? "Yes" : "No") << endl; }


int main() {
    int n = gi();
    vvi g(n);
    rep(i, n) {
        int u = gi() - 1;
        int k = gi();
        g[u] = gvi(k);
    }

    queue<int> q;
    vi dist(n, INF);
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        auto t = q.front(); q.pop();
        for (auto tt : g[t]) {
            if (dist[tt - 1] != INF) continue;
            umin(dist[tt - 1], dist[t] + 1);
            q.push(tt - 1);
        }
    }

    rep(i, dist.size()) {
        cout << i + 1 << " ";
        if (dist[i] == INF)
            cout << -1 << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}
