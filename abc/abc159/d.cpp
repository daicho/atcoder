#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (int i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (int i = (b - 1); i >= (a); i--)
#define rrep(i, ...) select(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define all(v) v.begin(), v.end()
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;


int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n, 0);

    rep(i, n)
        cin >> a[i];

    rep(i, n)
        b[a[i] - 1]++;

    ll sum = 0;

    rep(i, n)
        sum += b[i] * (b[i] - 1) / 2;

    rep(i, n) {
        ll t = b[a[i] - 1];
        cout << sum + 1 - t << endl;
    }

    return 0;
}
