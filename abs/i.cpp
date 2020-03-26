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
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;


int main() {
    string s;
    cin >> s;

    vector<string> smp = {"dream", "dreamer", "erase", "eraser"};

    while (true) {
        if (s.substr(0, 8) == "dreamera") {
            s = s.substr(5);
        } else if (s.substr(0, 7) == "dreamer") {
            s = s.substr(7);
        } else if (s.substr(0, 6) == "eraser") {
            s = s.substr(6);
        } else if (s.substr(0, 5) == "dream" || s.substr(0, 5) == "erase") {
            s = s.substr(5);
        } else {
            cout << "NO" << endl;
            return 0;
        }

        if (s == "")
            break;
    }

    cout << "YES" << endl;

    return 0;
}
