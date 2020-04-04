#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (int i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (int i = (b - 1); i >= (a); i--)
#define rrep(i, ...) select(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define umax(m, x) (m = max(m, x));
#define umin(m, x) (m = min(m, x));

#define rng(v) v.begin(), v.end()
#define rrng(v) v.rbegin(), v.rend()

#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

using ll = long long int;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvb = vector<vector<bool>>;

const int INF = 1e9;
const ll LINF = 1e18;

inline void yn(bool f) { cout << (f ? "Yes" : "No") << endl; }

map<ll, ll> prime_factor(ll n) {
    map<ll, ll> ret;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }

    if (n != 1)
        ret[n] = 1;

    return ret;
}


int main() {
    ll n;
    cin >> n;

    ll cnt = 0;

    map<ll, ll> pf1 = prime_factor(n);
    map<ll, ll> pf2 = prime_factor(n - 1);

    debug(pf1.size());
    for (auto p : pf1) {
        if (p.first == 1) continue;

        ll t = n;
        while (true) {
            if (t % p.first == 0) {
                t /= p.first;
            } else {
                t -= p.first;
            }
            if (t == 1) {
                cnt++;
                break;
            } else if (t < 1) {
                break;
            }
        }
    }

    for (auto pf2 : pf2) {
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
