#include <bits/stdc++.h>

#define _sel(_1, _2, x, ...) x
#define repn(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, ...) _sel(__VA_ARGS__, reps, repn)(i, __VA_ARGS__)
#define reppn(i, n) for (ll i = 1; i <= (n); i++)
#define repps(i, a, b) for (ll i = (a); i <= (b); i++)
#define repp(i, ...) _sel(__VA_ARGS__, repps, reppn)(i, __VA_ARGS__)
#define rrepn(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rreps(i, a, b) for (ll i = (b) - 1; i >= (a); i--)
#define rrep(i, ...) _sel(__VA_ARGS__, rreps, rrepn)(i, __VA_ARGS__)
#define rreppn(i, n) for (ll i = (n); i >= 1; i--)
#define rrepps(i, a, b) for (ll i = (b); i >= (a); i--)
#define rrepp(i, ...) _sel(__VA_ARGS__, rrepps, rreppn)(i, __VA_ARGS__)

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define rng(v) (v).begin(), (v).end()
#define rrng(v) (v).rbegin(), (v).rend()
#define _shv(v) for (auto _t1 : v) cerr << _t1 << " "; cerr << endl;
#define dg(x) cerr << #x << ": " << (x) << endl;
#define dgv(v) cerr << #v << ": "; _shv(v);
#define dgm(m) cerr << #m << ":" << endl; for (auto _t2 : m) { _shv(_t2); }

using namespace std;
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
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
const ll MOD = 1e9 + 7;
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

template<typename T> inline void pt(T x) { cout << x << endl; }
template<typename T> inline void inv(T& v) { for (auto& t : v) cin >> t; }
template<typename T> inline int siz(T& x) { return x.size(); }
template<typename T> inline ll pow2(T n) { return 1ll << n; }
template<typename T, typename U> inline int bit(T x, U n) { return x >> n & 1; }
template<typename T, typename U>
inline bool umax(T& m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U>
inline bool umin(T& m, U x) { if (m > x) { m = x; return true; } return false; }


ll calc(vvl& dp, vvl& dist, ll b, ll e) {
    if (dp[b][e] != -2) return dp[b][e];
    int k = siz(dist);
    vl t;
    rep(i, k) if (!bit(b, i)) t.pb(i);
    if (siz(t) == 1) {
        if (e == 0) return dp[b][e] = 0;
        else return dp[b][e] = -1;
    } else {
        if (e == 0) return dp[b][e] = -1;
    }
    dp[b][e] = INF;
    for (auto t1 : t) {
        if (t1 == e) continue;
        if (calc(dp, dist, b | (1 << e), t1) != -1)
            umin(dp[b][e], calc(dp, dist, b | (1 << e), t1) + dist[t1][e]);
    }
    if (dp[b][e] == INF) dp[b][e] = -1;
    return dp[b][e];
}

int main() {
    ll n, m;
    cin >> n >> m;
    vvl g(n);
    rep(i, m) {
        ll u, v;
        cin >> u >> v;
        g[u - 1].pb(v - 1);
        g[v - 1].pb(u - 1);
    }
    ll s;
    cin >> s;
    s--;
    ll k;
    cin >> k;
    vl t(k + 1);
    t[0] = s;
    repp(i, k) cin >> t[i], t[i]--;
    vvl dist(k + 1, vl(k + 1, -1));
    repp(i, 0, k) {
        queue<ll> q;
        vl td(n, -1);
        td[t[i]] = 0;
        q.push(t[i]);
        while (!q.empty()) {
            auto tt = q.front(); q.pop();
            for (auto t1 : g[tt]) {
                if (td[t1] == -1) {
                    td[t1] = td[tt] + 1;
                    q.push(t1);
                }
            }
        }
        repp(j, 0, k) {
            dist[i][j] = td[t[j]];
        }
    }

    vvl dp(pow2(k + 1), vl(k + 1, -2));
    ll ans = INF;
    repp(i, k)
        umin(ans, calc(dp, dist, 0, i));
    pt(ans);

    return 0;
}
