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
#define _shwv(v) for (auto _t1 : v) cerr << _t1 << " "; cerr << endl;
#define dbg(x) cerr << #x << ": " << (x) << endl;
#define dbgv(v) cerr << #v << ": "; _shwv(v);
#define dbgm(m) cerr << #m << ":" << endl; for (auto _t2 : m) { _shwv(_t2); }

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

template<typename T> inline void prt(T x) { cout << x << endl; }
template<typename T> inline void getv(T& v) { for (auto& t : v) cin >> t; }
template<typename T> inline int siz(T& x) { return x.size(); }
template<typename T> inline ll pow2(T n) { return 1ll << n; }
template<typename T, typename U> inline int bit(T x, U n) { return x >> n & 1; }
template<typename T, typename U>
inline bool umax(T& m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U>
inline bool umin(T& m, U x) { if (m > x) { m = x; return true; } return false; }


int main() {
    int n, m;
    cin >> n >> m;
    vi a(m), b(m);
    vvi r(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        r[a[i]].pb(b[i]);
        r[b[i]].pb(a[i]);
    }
    vb e(n, false);
    e[0] = true;
    queue<tuple<int, int, int>> q;
    q.push(mt(0, 0, -1));
    vi aaa(n, -1);
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        auto st = get<0>(t);
        auto nd = get<1>(t);
        auto rd = get<2>(t);
        rep(i, siz(r[st])) {
            if (e[r[st][i]]) continue;
            e[r[st][i]] = true;
            aaa[r[st][i]] = st;
            q.push(mt(r[st][i], nd + 1, st));
        }
    }
    bool f = true;
    rep(i, n) {
        if (!e[i]) {
            f = false;
            break;
        }
    }
    if (!f) {
        prt("No");
        return 0;
    } else {
        prt("Yes");
        rep(i, 1, n) prt(aaa[i] + 1);
    }

    return 0;
}
