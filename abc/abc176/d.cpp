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
    int h, w;
    cin >> h >> w;

    int ch, cw;
    cin >> ch >> cw;

    int dh, dw;
    cin >> dh >> dw;

    vvc s(h + 2, vc(w + 2, '#'));
    repp(i, h) repp(j, w) cin >> s[i][j];

    queue<pii> q;
    queue<pii> qq;
    q.push(mp(ch, cw));

    vvb f(h + 2, vb(w + 2, false));
    f[ch][cw] = 0;

    int ans = 0;

    while (true) {
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            bool ff = false;

            rep(i, 4) {
                int ty = t.fi + DY[i];
                int tx = t.se + DX[i];

                if (f[ty][tx]) continue;

                if (s[ty][tx] == '.') {
                    if (ty == dh && tx == dw) {
                        prt(ans);
                        return 0;
                    }

                    q.push(mp(ty, tx));
                    f[ty][tx] = true;
                } else {
                    ff = true;
                }
            }

            if (ff) qq.push(mp(t.fi, t.se));
        }

        if (qq.empty()) {
            prt(-1);
            return 0;
        }

        while (!qq.empty()) {
            auto t = qq.front(); qq.pop();

            repp(i, t.fi - 2, t.fi + 2) {
                if (i < 1 || i > h) continue;
                repp(j, t.se - 2, t.se + 2) {
                    if (j < 1 || j > w) continue;

                    if (s[i][j] == '.' && !f[i][j]) {
                        if (i == dh && j == dw) {
                            prt(ans + 1);
                            return 0;
                        }

                        q.push(mp(i, j));
                        f[i][j] = true;
                    }
                }
            }
        }

        ans++;
    }

    return 0;
}
