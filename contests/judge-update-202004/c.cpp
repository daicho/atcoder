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

using ll = long long int;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvb = vector<vector<bool>>;

const int INF = 1e9;
const ll LINF = 1e18;

inline void yn(bool f) { cout << (f ? "Yes" : "No") << endl; }


int main() {
    vi a(3);
    int sum = 0;

    vvi aa(3, vi(3, 0));

    rep(i, 3) {
        cin >> a[i];
        sum += a[i];
    }

    vi v(sum);
    iota(rng(v), 1);

    int cnt = 0;

    do {
        auto itr = v.begin();

        rep(i, 3) {
            rep(j, a[i])
                aa[i][j] = *(itr++);
        }

        bool f = true;
        rep(i, 3) {
            rep(j, a[i]) {
                if (i - 1 >= 0 && aa[i - 1][j] <= aa[i][j]) {
                    f = false;
                    break;
                }

                if (j - 1 >= 0 && aa[i][j - 1] <= aa[i][j]) {
                    f = false;
                    break;
                }
            }
        }

        if (f) cnt++;
    } while (next_permutation(rng(v)));

    cout << cnt << endl;

    return 0;
}
