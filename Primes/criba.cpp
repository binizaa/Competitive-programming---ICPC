#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int LIMITE = 1e6;
vector<int> spf(LIMITE + 1);
vector<int> primes;

void criba() {
    iota(spf.begin(), spf.end(), 0);
    for (int p = 2; p <= LIMITE; p++) {
        if (spf[p] == p) {
            primes.push_back(p);
            for (long long i = (long long)p*p; i <= LIMITE; i += p)
                if (spf[i] == i) spf[i] = p;
        }
    }

    cout << "spf: ";
    rep(i, 2, min(LIMITE + 1, 22)) cout << i << ":" << spf[i] << " ";
    cout << endl;

    cout << "primes: ";
    rep(i, 0, min((int)primes.size(), 20)) cout << primes[i] << " ";
    cout << endl;
}

vector<int> factors(int n) {
    vector<int> f;
    while (n > 1) {
        f.push_back(spf[n]);
        n /= spf[n];
    }
    return f;
}

bool comb(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    criba();
    int n;
    cin >> n;

    cout << "spf[" << n << "] = " << spf[n] << endl;

    vector<int> f = factors(n);
    cout << "factors(" << n << ") = ";
    for(auto p : f) cout << p << " ";
    cout << endl;
}