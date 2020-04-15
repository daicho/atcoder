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


typedef struct num {
    string str;
    int kind;
} Num;

Num num(string str, int kind) {
    Num a = {str, kind};
    return a;
}

int main() {
    int n;
    cin >> n;

    vector<vector<Num>> a(10);
    a[0].push_back(num("a", 1));

    rep(i, 1, 10) {
        for (auto b : a[i - 1]) {
            rep(j, b.kind + 1) {
                if (j < b.kind)
                    a[i].push_back(num(b.str + (char)('a' + j), b.kind));
                else
                    a[i].push_back(num(b.str + (char)('a' + j), b.kind + 1));
            }
        }
    }

    for (auto b : a[n - 1])
        cout << b.str << endl;

    return 0;
}
