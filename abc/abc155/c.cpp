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

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    sort(all(s));
    s.push_back("");

    string temp = "";
    int cnt = 0;
    int max = 0;
    vector<string> res;

    rep(i, n + 1) {
        if (temp == s[i]) {
            cnt++;
        } else {
            if (cnt == max) {
                if (temp != "")
                    res.push_back(temp);
            } else if (cnt > max) {
                max = cnt;
                res.clear();
                res.push_back(temp);
            }

            temp = s[i];
            cnt = 0;
        }
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}
