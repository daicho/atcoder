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
    int n, q;
    cin >> n >> q;

    vector<vector<bool>> f(n, vector<bool>(n, false));

    rep(i, q) {
        char c;
        cin >> c;

        if (c == '1') {
            int a, b;
            cin >> a >> b;

            f[a - 1][b - 1] = true;
        } else if (c == '2') {
            int a;
            cin >> a;

            rep(j, n) {
                if (j == a - 1) continue;
                if (f[j][a - 1])
                    f[a - 1][j] = true;
            }
        } else if (c == '3') {
            int a;
            cin >> a;

            vector<bool> temp(n);
            rep(j, n)
                temp[j] = f[a - 1][j];

            rep(j, n) {
                if (j == a - 1 || !temp[j]) continue;

                rep(q, n) {
                    if (q == a - 1) continue;
                    if (f[j][q])
                        f[a - 1][q] = true;
                }
            }
        }
    }

    rep(i, n) {
        rep(j, n)
            cout << (f[i][j] ? "Y" : "N");
        cout << endl;
    }

    return 0;
}
