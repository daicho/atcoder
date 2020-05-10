#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define CMAX(m, x) m = max(m, x);
#define CMIN(m, x) m = min(m, x);
#define itn int
typedef long long lint;
typedef long double ldouble;
const int INF = 1e9;
const lint LINF = 1e18;


// 反転した文字列を返す
string reverse(string str) {
    str.reserve();
    return str;
}

// rev : 反転するか
string parse(string str, bool rev = true) {
    string ans = "";
    int cnt = 0;
    int start = 0;

    REP(i, str.size()) {
        if (str[i] == '(') {
            if (cnt == 0)
                start = i;
            cnt++;
        } else if (str[i] == ')') {
            cnt--;
            if (cnt == 0)
                ans += parse(str.substr(start + 1, i - start - 1));
        } else if (cnt == 0) {
            ans += str[i];
        }
    }

    if (rev)
        ans += reverse(ans);

    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << parse(s, false) << endl;

    return 0;
}
