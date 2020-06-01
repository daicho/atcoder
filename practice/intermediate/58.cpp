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
#define dbg(x) dbgn(#x, x)

using namespace std;
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vvs = vector<vector<string>>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vector<vector<T>>>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

template<typename T> inline void errv(T& v) { for (auto x: v) cerr << x << " "; cerr << endl; }
inline void errv(vb& v) { for (auto x: v) cerr << (x ? 1 : 0) << " "; cerr << endl; }
template<typename T> inline void dbgn(string n, T x) { cerr << n << ": " << x << endl; }
inline void dbgn(string n, bool x) { cerr << n << ": " << (x ? "true" : "false") << endl; }
template<typename T> inline void dbgn(string n, vector<T>& v) { cerr << n << ": "; errv(v); }
template<typename T> inline void dbgn(string n, vv<T>& m) { cerr << n << ":" << endl; for (auto& v: m) errv(v); }
template<typename T> inline void prt(T x) { cout << x << endl; }
template<typename T> inline void getv(T& v) { for (auto& x: v) cin >> x; }
template<typename T> inline int siz(T& x) { return x.size(); }
template<typename T> inline ll pow2(T n) { return 1ll << n; }
template<typename T, typename U> inline int bit(T x, U n) { return x >> n & 1; }
template<typename T, typename U> inline bool umax(T& m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U> inline bool umin(T& m, U x) { if (m > x) { m = x; return true; } return false; }


int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    int p, q;
    cin >> p >> q;

    vi c(k);
    vi z(n, false);
    rep(i, k) {
        cin >> c[i];
        c[i]--;
        z[c[i]] = true;
    }

    vvi g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        g[a - 1].pb(b - 1);
        g[b - 1].pb(a - 1);
    }

    vb d(n, false);
    rep(i, k) {
        queue<pii> que;
        vb e(n, false);
        que.push(mp(c[i], 0));
        e[c[i]] = true;
        while (!que.empty()) {
            auto t = que.front(); que.pop();
            if (t.se > s) break;
            d[t.fi] = true;
            for (auto tt: g[t.fi]) {
                if (e[tt]) continue;
                e[tt] = true;
                que.push(mp(tt, t.se + 1));
            }
        }
    }

    pqg<pll> que;
    que.push(mp(0, 0));
    vl ans(n, -1);
    while (!que.empty()) {
        auto t = que.top(); que.pop();
        if (ans[t.se] != -1) continue;
        ans[t.se] = t.fi;
        for (auto tt: g[t.se]) {
            if (ans[tt] != -1) continue;
            if (z[tt]) continue;
            que.push(mp(t.fi + ((tt == n - 1) ? 0 : (d[tt] ? q : p)), tt));
        }
    }

    prt(ans.back());

    return 0;
}
