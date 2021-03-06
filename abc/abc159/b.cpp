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
    string s;
    cin >> s;

    rep(i, s.length()) {
        if (s[i] != s[s.length() - 1 - i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    rep(i, (s.length() - 1) / 2) {
        if (s[i] != s[(s.length() - 1) / 2 - 1 - i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
