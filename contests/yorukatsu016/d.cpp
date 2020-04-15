#include <bits/stdc++.h>
 
#define select(_1, _2, x, ...) x
 
#define repn(i, n) for (int i = 0; i < (n); i++)
#define repr(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, ...) select(__VA_ARGS__, repr, repn)(i, __VA_ARGS__)
 
using namespace std;
 
using ll = long long int;
 
struct node {
    ll num;
    string all;
};
 
int main() {
    ll k;
    cin >> k;
 
    if (k <= 9) {
        cout << k << endl;
        return 0;
    }
 
    queue<struct node> q;
    rep(i, 1, 10) {
        struct node temp = {i, to_string(i)};
        q.push(temp);
    }
 
    ll cnt = 0;
 
    struct node t;
    while (cnt < k) {
        t = q.front(); q.pop();
        rep(i, t.num - 1, t.num + 2) {
            if (i < 0 || i > 9) continue;
            struct node temp = {i, t.all + to_string(i)};
            q.push(temp);
        }
        cnt++;
    }
 
    cout << t.all << endl;
 
    return 0;
}
