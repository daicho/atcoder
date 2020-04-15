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
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    vector<int> dp_a(n);
    vector<int> dp_b(n);
    vector<int> dp_c(n);

    dp_a[0] = a[0];
    dp_b[0] = b[0];
    dp_c[0] = c[0];

    repr(i, 1, n) {
        dp_a[i] = max(dp_b[i - 1] + a[i], dp_c[i - 1] + a[i]);
        dp_b[i] = max(dp_a[i - 1] + b[i], dp_c[i - 1] + b[i]);
        dp_c[i] = max(dp_a[i - 1] + c[i], dp_b[i - 1] + c[i]);
    }

    cout << max({dp_a[n - 1], dp_b[n - 1], dp_c[n - 1]}) << endl;

    return 0;
}
