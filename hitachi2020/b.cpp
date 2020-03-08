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
    int A, B, M;
    cin >> A >> B >> M;

    vector<int> a(A);
    vector<int> b(B);

    int min_a = INF;
    int min_b = INF;

    rep(i, A) {
        cin >> a[i];
        if (a[i] < min_a)
            min_a = a[i];
    }

    rep(i, B) {
        cin >> b[i];
        if (b[i] < min_b)
            min_b = b[i];
    }

    int min = min_a + min_b;

    rep(i, M) {
        int x, y, c;
        cin >> x >> y >> c;
        if (a[x - 1] + b[y - 1] - c < min)
            min = a[x - 1] + b[y - 1] - c;
    }

    cout << min << endl;

    return 0;
}
