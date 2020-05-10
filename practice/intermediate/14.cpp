#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define umax(m, x) (m = max(m, x))
#define umin(m, x) (m = min(m, x))

#define bit(x, n) ((x) >> (n) & 1)

using namespace std;
using ll = long long int;
using vl = vector<ll>;

const int INF = 1e9;
const ll LINF = 1e18;


typedef struct bit {
    int b; // ビット列
    int t; // 1の残り数
    int f; // 0の残り数
} Bit;

int main() {
    int n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, n) cin >> a[i];

    stack<Bit> s;
    s.push({1, k - 1, n - k});

    ll ans = LINF;

    // 深さ優先探索で, 1がk個, 0がn-k個のビットの組み合わせを列挙
    while (!s.empty()) {
        Bit cur = s.top(); s.pop();

        // ビット列が完成したら
        if (cur.t == 0 && cur.f == 0) {
            ll high = 0; // 一番高い建物の高さ
            ll cost = 0; // 総コスト

            rep(i, n) {
                // 建物が見えていなかったら
                if (a[i] <= high) {
                    // ビットが建ってる(見えるべき建物)だったら
                    if (bit(cur.b, n - 1 - i)) {
                        cost += high + 1 - a[i];
                        high = high + 1;
                    }
                } else {
                    high = a[i];
                }
            }

            umin(ans, cost);

            continue;
        }

        if (cur.t > 0)
            s.push({(cur.b << 1) + 1, cur.t - 1, cur.f});

        if (cur.f > 0)
            s.push({cur.b << 1, cur.t, cur.f - 1});
    };

    cout << ans << endl;

    return 0;
}
