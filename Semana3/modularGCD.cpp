#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll modmul(ll a, ll b, ll m) {
    return (__int128)a * b % m;
}

ll modpow(ll x, ll n, ll m) {
    ll res = 1 % m;
    x %= m;
    while (n > 0) {
        if (n % 2 == 1) res = modmul(res, x, m);
        x = modmul(x, x, m);
        n /= 2;
    }
    return res;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    ll a, b, n;
    if (!(cin >> a >> b >> n)) return;

    ll diff = abs(a - b);
    ll MOD = 1e9 + 7;

    if (diff == 0) {
        cout << (modpow(a, n, MOD) + modpow(b, n, MOD)) % MOD << endl;
    } else {

        ll term1 = modpow(a, n, diff);
        ll term2 = modpow(b, n, diff);
        ll res = gcd((term1 + term2) % diff, diff);
        cout << res % MOD << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}