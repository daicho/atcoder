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

    if (
        s[0] < '0' || s[0] > '9' ||
        s[1] < '0' || s[1] > '9' ||
        s[2] < '0' || s[2] > '9'
    ) {
        cout << "error" << endl;
        return 0;
    }

    int num;
    num =
        (s[0] - '0') * 100 + 
        (s[1] - '0') * 10 + 
        (s[2] - '0') * 1;

    cout << num * 2 << endl;

    return 0;
}
