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
    bool rev = false;

    string sf = "";

    string s;
    cin >> s;

    int n;
    cin >> n;

    rep(i, n) {
        int t;
        cin >> t;

        if (t == 1) {
            rev = !rev;
        } else {
            int f;
            char c;
            cin >> f >> c;

            if (f == 1) {
                if (rev)
                    s.push_back(c);
                else
                    sf.push_back(c);
            } else {
                if (rev)
                    sf.push_back(c);
                else
                    s.push_back(c);
            }
        }
    }

    if (rev) {
        rrep(i, s.length())
            cout << s[i];
        cout << sf << endl;
    } else {
        rrep(i, sf.length())
            cout << sf[i];
        cout << s << endl;
    }

    return 0;
}
