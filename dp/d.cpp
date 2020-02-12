#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (int i = (b - 1); i >= (a); i--)

#define all(v) (v).begin(), (v).end();
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

int main() {
    int N, W;
    cin >> N >> W;

    vector<ll> w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    vector<vector<ll>> dp(N, vector<ll>(W));


    return 0;
}
