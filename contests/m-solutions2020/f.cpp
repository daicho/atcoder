#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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
template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vector<vector<T>>>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

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
#define siz(x) int((x).size())
#define pow2(x) (1ll << (x))
#define bit(x, n) ((x) >> (n) & 1)
#define prt(x) cout << (x) << endl
#define dbg(x) dbgn(#x, x)

template<typename T, typename U> inline bool umax(T& m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U> inline bool umin(T& m, U x) { if (m > x) { m = x; return true; } return false; }
template<typename T> inline void errv(T& v) { for (auto x: v) cerr << x << " "; cerr << endl; }
inline void errv(vb& v) { for (auto x: v) cerr << (x ? 1 : 0) << " "; cerr << endl; }
template<typename T> inline void dbgn(string n, T x) { cerr << n << ": " << x << endl; }
template<typename T> inline void dbgn(string n, vector<T>& v) { cerr << n << ": "; errv(v); }
template<typename T> inline void dbgn(string n, vv<T>& m) { cerr << n << ":" << endl; for (auto& v: m) errv(v); }


int main() {
    ll n;
    cin >> n;

    vl x(n), y(n);
    vc u(n);
    rep(i, n) cin >> x[i] >> y[i] >> u[i];

    vector<multiset<pair<int, int>>> tx(200002), ty(200002);
    vector<multiset<pair<int, int>>> p(400002), m(400002);
    rep(i, n) {
        if (u[i] == 'D')
            tx[x[i]].insert(mp(y[i], i));

        if (u[i] == 'L')
            tx[y[i]].insert(mp(x[i], i));

        if (u[i] == 'U' || u[i] == 'D') {
            p[x[i] + y[i]].insert(mp(x[i], i));
            m[x[i] - y[i] + 200000].insert(mp(x[i], i));
        }
    }

    ll ans = LINF;

    rep(i, n) {
        if (u[i] == 'R') {
            if (!p[x[i] + y[i]].empty()) {
                auto l = p[x[i] + y[i]].lower_bound(mp(x[i], 0));
                if (l != p[x[i] + y[i]].end())
                    umin(ans, ((*l).fi - x[i]) * 10);
            }

            if (!p[x[i] - y[i] + 200000].empty()) {
                auto l = p[x[i] - y[i] + 200000].lower_bound(mp(x[i], 0));
                if (l != p[x[i] - y[i] + 200000].end())
                    umin(ans, ((*l).fi - x[i]) * 10);
            }
        }

        if (u[i] == 'L') {
            if (!p[x[i] + y[i]].empty()) {
                auto l = p[x[i] + y[i]].upper_bound(mp(x[i], 0));
                if (l != p[x[i] + y[i]].begin())
                    umin(ans, (x[i] - (*--l).fi) * 10);
            }

            if (!p[x[i] - y[i] + 200000].empty()) {
                auto l = p[x[i] - y[i] + 200000].upper_bound(mp(x[i], 0));
                if (l != p[x[i] - y[i] + 200000].begin()) {
                    umin(ans, (x[i] - (*--l).fi) * 10);
                }
            }
        }

        if (u[i] == 'U') {
            if (!tx[x[i]].empty()) {
                auto l = tx[x[i]].lower_bound(mp(y[i], 0));
                if (l != tx[x[i]].end())
                    umin(ans, ((*l).fi - y[i]) * 10 / 2);
            }
        }

        if (u[i] == 'R') {
            if (!ty[y[i]].empty()) {
                auto l = ty[y[i]].lower_bound(mp(x[i], 0));
                if (l != ty[y[i]].end())
                    umin(ans, ((*l).fi - x[i]) * 10 / 2);
            }
        }
    }

    if (ans == LINF)
        prt("SAFE");
    else
        prt(ans);

    return 0;
}
