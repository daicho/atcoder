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

    vector<string> ss;
    string temp = "";

    bool stat = false;

    for(auto c : s) {
        if (c >= 'A' && c <= 'Z') {
            temp.push_back(c + 'a' - 'A');

            if (stat) {
                stat = false;
                ss.push_back(temp);
                temp = "";
            } else {
                stat = true;
            }
        } else {
            temp.push_back(c);
        }
    }

    sort(all(ss));

    for(auto tss : ss) {
        tss[0] += 'A' - 'a';
        tss[tss.length() - 1] += 'A' - 'a';
        cout << tss;
    }
    cout << endl;

    return 0;
}
