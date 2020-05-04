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

typedef struct cell {
    int cur;
    pair<int, int> pos;
} Cell;


int main() {
    int n, m;
    cin >> n >> m;

    vvi map(n, vi(m));
    vector<vector<pair<int, int>>> table(11);

    rep(i, n) {
        string s;
        cin >> s;

        rep(j, m) {
            if (s[j] == 'S')
                map[i][j] = 0;
            else if (s[j] == 'G')
                map[i][j] = 10;
            else
                map[i][j] = s[j] - '0';

            table[map[i][j]].push_back(make_pair(j, i));
        }
    }

    priority_queue<
        pair<int, pair<int, pair<int, pair<int, int>>>>,
        vector<pair<int, pair<int, pair<int, pair<int, int>>>>>,
        greater<pair<int, pair<int, pair<int, pair<int, int>>>>>
    > q;
    q.push(make_pair(abs(table[10][0].first - table[0][0].first) + abs(table[10][0].second - table[0][0].second), make_pair(0, make_pair(0, table[0][0]))));

    while (true) {
        auto t = q.top(); q.pop();

        if (t.second.second.first == 10) {
            cout << t.second.first << endl;
            return 0;
        }

        if (table[t.second.second.first + 1].size() == 0) {
            cout << -1 << endl;
            return 0;
        }

        for (auto c : table[t.second.second.first + 1]) {
            q.push(make_pair(
                abs(table[0][0].first - c.first) + abs(table[0][0].second - c.second) +
                abs(table[10][0].first - c.first) + abs(table[10][0].second - c.second) + abs(t.second.second.second.first - c.first) + abs(t.second.second.second.second - c.second),
                make_pair(
                t.second.first + abs(t.second.second.second.first - c.first) + abs(t.second.second.second.second - c.second),
                make_pair(t.second.second.first + 1, c)))
            );
        }
    }
    

    return 0;
}
