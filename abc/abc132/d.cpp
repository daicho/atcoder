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

template<ll mod> struct mint {
    ll x;
    mint(ll x = 0): x((x + mod) % mod) { }
    mint operator+(mint a) { return mint(*this) += a; }
    mint operator-(mint a) { return mint(*this) -= a; }
    mint operator*(mint a) { return mint(*this) *= a; }
    mint operator/(mint a) { return mint(*this) /= a; }
    mint& operator+=(mint a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(mint a) { if ((x += mod - a.x) >= mod) x -= mod; return *this; }
    mint& operator*=(mint a) { (x *= a.x) %= mod; return *this; }
    mint& operator/=(mint a) { return *this *= a.inv(); }
    mint pow(ll t) { mint a = x, ret = 1; while (t) { if (t & 1) ret *= a; a *= a; t >>= 1; } return ret; }
    mint inv() { return pow(mod - 2); }
    friend istream& operator>>(istream& is, mint& a) { return is >> a.x; }
    friend ostream& operator<<(ostream& os, mint& a) { return os << a.x; }
};


int main() {
    int n, k;
    cin >> n >> k;

    repp(i, k) {
        mint<MOD> ans = 0;
        mint<MOD> t;

        if (n == k) {
            if (i == 1)
                prt(1);
            else
                prt(0);

            continue;
        }

        if (n - k - i + 1 >= 0 && i >= 2) {
            t = 1;
            repp(j, n - k - 1) t *= j;
            repp(j, n - k - i + 1) t /= j;
            repp(j, i - 2) t /= j;
            ans += t;
        }

        if (n - k - i >= 0) {
            t = 1;
            repp(j, n - k - 1) t *= j;
            repp(j, n - k - i) t /= j;
            repp(j, i - 1) t /= j;
            ans += t * 2;
        }

        if (n - k - i - 1 >= 0) {
            t = 1;
            repp(j, n - k - 1) t *= j;
            repp(j, n - k - i - 1) t /= j;
            repp(j, i) t /= j;
            ans += t;
        }

        t = 1;
        repp(j, k - 1) t *= j;
        repp(j, k - i) t /= j;
        repp(j, i - 1) t /= j;
        ans *= t;

        prt(ans);
    }

    return 0;
}
