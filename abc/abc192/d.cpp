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
#define fi first
#define se second
#define rng(v) (v).begin(), (v).end()
#define rrng(v) (v).rbegin(), (v).rend()
#define siz(x) int((x).size())
#define pow2(x) (1ll << (x))
#define bit(x, n) ((x) >> (n) & 1)
#define prt(x) cout << (x) << endl
#define dbg(x) dbgn(#x, x)
#define dec() cout << fixed << setprecision(15)

template<typename T, typename U> inline bool umax(T& m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U> inline bool umin(T& m, U x) { if (m > x) { m = x; return true; } return false; }
template<typename T> inline void errv(T& v) { for (auto x: v) cerr << x << " "; cerr << endl; }
inline void errv(vb& v) { for (auto x: v) cerr << (x ? 1 : 0) << " "; cerr << endl; }
template<typename T> inline void dbgn(string n, T x) { cerr << n << ": " << x << endl; }
template<typename T> inline void dbgn(string n, vector<T>& v) { cerr << n << ": "; errv(v); }
template<typename T> inline void dbgn(string n, vv<T>& m) { cerr << n << ":" << endl; for (auto& v: m) errv(v); }

struct UnionFind {
    vi p;
    UnionFind(int n): p(n, -1) { }
    int root(int x) { if (p[x] < 0) return x; else return p[x] = root(p[x]); }
    int size(int x) { return -p[root(x)]; }
    void unite(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry) return; if (p[rx] > p[ry]) swap(rx, ry);
        p[rx] += p[ry]; p[ry] = rx;
    }
};

ll MOD = 1e9 + 7;
//ll MOD = 998244353;

struct mint {
    ll x;
    mint(ll a = 0): x((a + MOD) % MOD) { }
    mint operator+(mint a) { return mint(*this) += a; }
    mint operator-(mint a) { return mint(*this) -= a; }
    mint operator*(mint a) { return mint(*this) *= a; }
    mint operator/(mint a) { return mint(*this) /= a; }
    mint& operator+=(mint a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
    mint& operator-=(mint a) { if ((x += MOD - a.x) >= MOD) x -= MOD; return *this; }
    mint& operator*=(mint a) { (x *= a.x) %= MOD; return *this; }
    mint& operator/=(mint a) { return *this *= a.inv(); }
    mint pow(ll t) { mint a = x, ret = 1; while (t) { if (t & 1) ret *= a; a *= a; t >>= 1; } return ret; }
    mint inv() { return pow(MOD - 2); }
    friend istream& operator>>(istream& is, mint& a) { return is >> a.x; }
    friend ostream& operator<<(ostream& os, mint& a) { return os << a.x; }
};

int main() {
    string s;
    ll m;
    cin >> s >> m;
    reverse(rng(s));

    if (siz(s) == 1) {
        if (m >= s[0] - '0')
            prt(1);
        else
            prt(0);

        return 0;
    }

    ll ma = 0;
    for (auto c: s) {
        umax(ma, c - '0');
    }

    __int128 l = ma;
    __int128 r = 1000000000000000001;

    while (r - l > 1) {
        ll mid = (l + r) / 2;

        __int128 w = 1;
        __int128 t = 0;
        bool f = true;

        rep(i, siz(s)) {
            if (w > m) {
                f = false;
                break;
            }
            __int128 x = s[i] - '0';
            t += x * w;
            w *= mid;
        }

        if (f && t <= m)
            l = mid;
        else
            r = mid;
    }

    prt((ll)r - ma - 1);

    return 0;
}
