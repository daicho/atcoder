#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
const ll MOD = 998244353;

template<ll mod> struct mint {
    ll x;
    mint(ll a = 0): x((a + mod) % mod) { }
    mint operator+(mint a) { return mint(*this) += a; }
    mint operator-(mint a) { return mint(*this) -= a; }
    mint operator*(mint a) { return mint(*this) *= a; }
    mint operator/(mint a) { return mint(*this) /= a; }
    mint& operator+=(mint a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(mint a) { if ((x += mod - a.x) >= mod) x -= mod; return *this; }
    mint& operator*=(mint a) { (x *= a.x) %= mod; return *this; }
    mint& operator/=(mint a) { return *this *= a.inv(); }
    mint pow(ll t) { mint a = x, ret = 1; while (t) { if (t & 1) ret *= a; a *= a; t >>= 1; } return ret; }
    mint inv() { return pow(mod - 2); }
    friend istream& operator>>(istream& is, mint& a) { return is >> a.x; }
    friend ostream& operator<<(ostream& os, mint& a) { return os << a.x; }
};

// 初項a, 公差d, 項数nの等差数列の和
mint<MOD> sum_touhi(mint<MOD> a, mint<MOD> d, mint<MOD> n) {
    mint<MOD> ret = (a * 2 + (n - 1) * d) * n / 2;
    return ret;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    mint<MOD> sum1 = sum_touhi(1, 1, c);
    mint<MOD> sum2 = sum_touhi(sum1, sum1, b);
    mint<MOD> sum3 = sum_touhi(sum2, sum2, a);

    cout << sum3 << endl;

    return 0;
}
