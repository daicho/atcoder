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
#define dbg(x) cerr << #x << ": " << (x) << endl;
#define dbgv(v) cerr << #v << ": "; _shv(v);
#define dbgm(m) cerr << #m << ":" << endl; for (auto _t2 : m) { _shv(_t2); }

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
using vpii = vector<pii>;
using vpll = vector<pll>;
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

inline void yn(bool f) { cout << (f ? "Yes" : "No") << endl; }
template<typename T> inline void prt(T x) { cout << (x) << endl; }
template<typename T> inline void prtv(T& v) { for (auto t : v) cout << t << " "; cout << endl; }
template<typename T> inline void prtl(T& v) { for (auto t : v) cout << t << endl; }
template<typename T> inline T pop(stack<T>& x) { T t = x.top(); x.pop(); return t; }
template<typename T> inline T pop(queue<T>& x) { T t = x.front(); x.pop(); return t; }
template<typename T> inline T pop(priority_queue<T>& x) { T t = x.top(); x.pop(); return t; }
template<typename T> inline int sz(T& x) { return x.size(); }
template<typename T> inline ll pow2(T n) { return 1ll << n; }
template<typename T, typename U> inline int bit(T x, U n) { return x >> n & 1; }

template<typename T, typename U>
inline void getv(T& v, U n) { v = T(n); rep(i, n) cin >> v[i]; }
template<typename T, typename U>
inline void inv(T& v, U n) { v = T(n); rep(i, n) { cin >> v[i]; v[i]--; } }
template<typename T, typename U>
inline void getm(T& v, U r, U c) { v = T(r); rep(i, r) getv(v[i], c); }
template<typename T, typename U>
inline void inm(T& v, U r, U c) { v = T(r); rep(i, r) inv(v[i], c); }
template<typename T, typename U>
inline bool cmax(T& m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U>
inline bool cmin(T& m, U x) { if (m > x) { m = x; return true; } return false; }


int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector<vvi> m(h, vvi(w, vi(4, 0)));
        rep(i, w) {
            m[0][i][3] = 1;
            m[h - 1][i][1] = 1;
        }
        rep(j, h) {
            m[j][0][2] = 1;
            m[j][w - 1][0] = 1;
        }
        rep(i, (2 * h - 1)) {
            if (i % 2 == 0) {
                rep(j, w - 1) {
                    int wall;
                    cin >> wall;
                    if (wall) {
                        m[i / 2][j][0] = 1;
                        m[i / 2][j + 1][2] = 1;
                    }
                }
            } else {
                rep(j, w) {
                    int wall;
                    cin >> wall;
                    if (wall) {
                        m[i / 2][j][1] = 1;
                        m[i / 2 + 1][j][3] = 1;
                    }
                }
            }
        }
        vvb e(h, vb(w, false));
        queue<pair<pii, int>> q;
        q.push(mp(mp(0, 0), 1));
        e[0][0] = true;
        int ans = 0;
        while (!q.empty()) {
            auto t = pop(q);
            rep(i, 4) {
                if (m[t.fi.se][t.fi.fi][i] == 0) {
                    int x = DX[i] + t.fi.fi;
                    int y = DY[i] + t.fi.se;
                    if (e[y][x]) continue;
                    if (x == w - 1 && y == h - 1) {
                        ans = t.se + 1;
                        break;
                    }
                    e[y][x] = true;
                    q.push(mp(mp(x, y), t.se + 1));
                }
            }
            if (ans) break;
        }
        prt(ans);
    }

    return 0;
}
