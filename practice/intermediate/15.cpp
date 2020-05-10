#include <bits/stdc++.h>

#define select(_1, _2, x, ...) x

#define repn(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)

#define rrepn(i, n) for (ll i = (n - 1); i >= 0; i--)
#define rrepr(i, a, b) for (ll i = (b - 1); i >= (a); i--)
#define rrep(i, ...) select(__VA_ARGS__, rrepr, rrepn)(i, __VA_ARGS__)

#define umax(m, x) (m = max(m, x))
#define umin(m, x) (m = min(m, x))

#define rng(v) v.begin(), v.end()
#define rrng(v) v.rbegin(), v.rend()

#define bit(x, n) ((x) >> (n) & 1)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

using ll = long long int;

using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;

const int INF = 1e9;
const ll LINF = 1e18;

inline void yn(bool f) { cout << (f ? "Yes" : "No") << endl; }


double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

typedef struct node {
    pair<int, int> p;
    double dist;
    vi left;
} Node;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> p(n);
    stack<Node> node;

    rep(i, n) {
        cin >> p[i].first >> p[i].second;

        vi left;
        rep(j, n)
            if (j != i) left.push_back(j);

        node.push({p[i], 0, left});
    }

    double sum = 0;
    int cnt = 0;

    while (!node.empty()) {
        Node cur = node.top(); node.pop();
        if (cur.left.empty()) {
            sum += cur.dist;
            cnt++;
        } else {
            for (auto i : cur.left) {
                vi left;
                for (auto j : cur.left)
                    if (j != i) left.push_back(j);

                node.push({p[i], cur.dist + dist(cur.p, p[i]), left});
            }
        }
    }

    cout << fixed << setprecision(10) << sum / cnt << endl;

    return 0;
}
