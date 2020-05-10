#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (ll i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (ll i = (b - 1); i >= (a); i--)
#define rrep(i, ...) select(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define umax(m, x) (m = max(m, x))
#define umin(m, x) (m = min(m, x))

#define rng(v) v.begin(), v.end()
#define rrng(v) v.rbegin(), v.rend()

#define bit(x, n) ((x) >> (n) & 1)

#define showv(v) for (auto __tmp1 : v) cerr << __tmp1 << " "; cerr << endl;
#define db(x) cerr << #x << ": " << (x) << endl;
#define dbv(v) cerr << #v << ": "; showv(v);
#define dbm(m) cerr << #m << ":" << endl; for (auto __tmp2 : m) { showv(__tmp2); }

using namespace std;

using ll = long long int;
using ld = long double;

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

int t = 1;
vl d, f;

void dfs(vvl& g, int v) {
    if (d[v]) return;
    d[v] = t++;
    for (auto n : g[v])
        dfs(g, n);
    f[v] = t++;
}

int main() {
    int n;
    cin >> n;

    vvl g(n);
    rep(i, n) {
        int u, k;
        cin >> u >> k;

        rep(j, k) {
            int v;
            cin >> v;
            g[u - 1].push_back(v - 1);
        }
    }

    d = vl(n, 0);
    f = vl(n, 0);

    rep(i, n)
        dfs(g, i);

    rep(i, n)
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;

    return 0;
}
