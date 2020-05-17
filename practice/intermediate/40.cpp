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

template<typename T> inline int siz(T& x) { return x.size(); }
template<typename T> inline ll pow2(T n) { return 1ll << n; }
template<typename T, typename U> inline int bit(T x, U n) { return x >> n & 1; }
template<typename T> inline void prt(T x) { cout << x << endl; }
template<typename T, typename U>
inline void getv(T& v, U n) { v = T(n); rep(i, n) cin >> v[i]; }
template<typename T, typename U>
inline bool umax(T& m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U>
inline bool umin(T& m, U x) { if (m > x) { m = x; return true; } return false; }


int main() {
    int n, k;
    cin >> n >> k;
    vi p(n, -1);
    rep(i, k) {
        int a, b;
        cin >> a >> b;
        p[a - 1] = b - 1;
    }
    vvl dp(n, vl(3, 0));
    vvl dp2(n, vl(3, 0));
    if (p[0] != -1) {
        dp[0][p[0]] = 1;
        dp2[0][p[0]] = 1;
    } else {
        rep(i, 3) dp[0][i] = 1;
        rep(i, 3) dp2[0][i] = 1;
    }
    
    rep(i, n - 1) {
        if (p[i + 1] != -1) {
            rep(j, 3) {
                dp[i + 1][p[i + 1]] += (j == p[i + 1]) ? dp2[i][j] : dp[i][j];
                dp2[i + 1][p[i + 1]] += (j == p[i + 1]) ? 0 : dp[i][j];
                dp[i + 1][p[i + 1]] %= 10000;
                dp2[i + 1][p[i + 1]] %= 10000;
            }
        } else {
            rep(j, 3) {
                rep(k, 3) {
                    dp[i + 1][j] += (j == k) ? dp2[i][k] : dp[i][k];
                    dp2[i + 1][j] += (j == k) ? 0 : dp[i][k];
                    dp[i + 1][j] %= 10000;
                    dp2[i + 1][j] %= 10000;
                }
            }
        }
    }
    prt((dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % 10000);

    return 0;
}
