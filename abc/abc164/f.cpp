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


int main() {
    int n;
    cin >> n;

    vb s(n), t(n);
    vl u(n), v(n);
    rep(i, n) {
        int q;
        cin >> q;
        s[i] = (q == 1);
    }
    rep(i, n) {
        int q;
        cin >> q;
        t[i] = (q == 1);
    }
    rep(i, n) {
        cin >> u[i];
    }
    rep(i, n) {
        cin >> v[i];
    }

    vector<vector<vector<int>>> x(n, vvi(n, vi(64, -1)));
    vvi r(n, vi(64, -1));
    vvi c(n, vi(64, -1));
    rep(i, n) {
        if (s[i]) {
            rep(j, 64) {
                if (((u[i] >> j) & 1) == 0) {
                    rep(k, n) {
                        if (x[i][k][j] == 1) {
                            cout << "-1" << endl;
                            return 0;
                        }
                        x[i][k][j] = 0;
                    }
                } else {
                    if (r[i][j] == 0 || r[i][j] == 2)
                        r[i][j] = 2;
                    r[i][j] = 1;
                }
            }
        } else {
            rep(j, 64) {
                if (((u[i] >> j) & 1) == 1) {
                    rep(k, n) {
                        if (x[i][k][j] == 0) {
                            cout << "-1" << endl;
                            return 0;
                        }
                        x[i][k][j] = 1;
                    }
                } else {
                    if (r[i][j] == 1 || r[i][j] == 2)
                        r[i][j] = 2;
                    r[i][j] = 0;
                }
            }
        }
    }

    rep(i, n) {
        if (t[i]) {
            rep(j, 64) {
                if (((v[i] >> j) & 1) == 0) {
                    rep(k, n) {
                        if (x[k][i][j] == 1) {
                            cout << "-1" << endl;
                            return 0;
                        }
                        x[k][i][j] = 0;
                    }
                } else {
                    if (c[i][j] == 0 || c[i][j] == 2)
                        c[i][j] = 2;
                    c[i][j] = 1;
                }
            }
        } else {
            rep(j, 64) {
                if (((v[i] >> j) & 1) == 1) {
                    rep(k, n) {
                        if (x[k][i][j] == 0) {
                            cout << "-1" << endl;
                            return 0;
                        }
                        x[k][i][j] = 1;
                    }
                } else {
                    if (c[i][j] == 1 || c[i][j] == 2)
                        c[i][j] = 2;
                    c[i][j] = 0;
                }
            }
        }
    }

    vvb r0(n, vb(64, false));
    vvb r1(n, vb(64, false));
    vvb c0(n, vb(64, false));
    vvb c1(n, vb(64, false));

    rep(i, n) {
        rep(j, n) {
            rrep(k, 64) {
                if (x[i][j][k] == 1) {
                    r1[i][k] = true;
                    c1[j][k] = true;
                } else {
                    r0[i][k] = true;
                    c0[j][k] = true;
                }
            }
        }
    }

    rep(i, n) {
        rep(j, 64) {
            if (r[i][j] == 1 && r1[i][j] == false) {
                bool f = true;
                rep(k, n) {
                    if (x[i][k][j] == -1) {
                        x[i][k][j] = 3;
                        c1[k][j] = true;
                        f = false;
                    }
                }
                if (f) {
                    cout << "-1" << endl;
                    return 0;
                }
            }

            if (r[i][j] == 0 && r0[i][j] == false) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    rep(i, n) {
        rep(j, 64) {
            if (c[i][j] == 1 && c1[i][j] == false) {
                bool f = true;
                rep(k, n) {
                    if (x[k][i][j] == -1 || x[k][i][j] == 3) {
                        x[k][i][j] = 1;
                        f = false;
                        break;
                    }
                }
                if (f) {
                    cout << "-1" << endl;
                    return 0;
                }
            }

            if (c[i][j] == 0 && c0[i][j] == false) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    rep(i, n) {
        rep(j, n) {
            ll temp = 0;
            rrep(k, 64) {
                temp *= 2;
                temp += (x[i][j][k] == -1 || x[i][j][k] == 3) ? 0 : x[i][j][k];
            }
            cout << temp << " ";
        }
        cout << endl;
    }

    return 0;
}
