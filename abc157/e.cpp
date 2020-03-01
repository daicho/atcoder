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
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll q;
    cin >> q;

    vector<vector<int>> tb(s.length() + 1, vector<int>(26, 0));
    rep(i, s.length()) {
        rep(j, 26) {
            tb[i + 1][j] = tb[i][j];
        }
        tb[i + 1][s[i] - 'a']++;
    }

    rep(j, q) {
        int type;
        cin >> type;

        if (type == 1) {
            int i;
            char c;
            cin >> i >> c;
            if (s[i - 1] == c) continue;

            rep(x, i, s.size() + 1) tb[x][s[i - 1] - 'a']--;
            s[i - 1] = c;
            rep(x, i, s.size() + 1) tb[x][s[i - 1] - 'a']++;
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            int count = 0;
            rep (k, 26) {
                if (tb[r][k] - tb[l - 1][k] > 0) count++;
            }
            cout << count << endl;
        }
    }

    return 0;
}
