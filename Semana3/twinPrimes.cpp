// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1335

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
#define rep(i,a,b) for(ll i=a; i<b; i++)

const int LIMITE = 10000;
vector<bool> es_primo(LIMITE + 1, true);
vector<ll> primes;

// ICPC
void criba() {
    es_primo[0] = es_primo[1] = false;
    int last = 2;
    for (int p = 2; (long long)p * p <= LIMITE; p++) {
        if (es_primo[p])
            primes.push_back(p);
            for (int i = p * p; i <= LIMITE; i += p)
                es_primo[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    criba();

    for(auto i : primes) cout<<i<<" ";

    // int n; 
    
    // while(cin>>n)
    //     cout<<"("<<primes[2*n-1]<<", "<<primes[n*2]<<")";
}