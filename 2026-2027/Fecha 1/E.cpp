#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int tam = 1;
vector<int> list;

const int LIMITE = 1e6;
vector<bool> isPrime(LIMITE + 1, true);
vector<int> primes;
//O(n log n)
vector<int> spf(LIMITE + 1); 

void criba() {
    iota(spf.begin(), spf.end(), 0); 
    for (int p = 2; p <= LIMITE; p++) {
        if (spf[p] == p) { 
            primes.push_back(p);
            for (long long i = (long long)p * p; i <= LIMITE; i += p)
                if (spf[i] == i) spf[i] = p;
        }
    }
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
    int m,n;

    cin>>n>>m;

    vector<pair<int,vector<int>>> order;
    vector<int> querys(m);
    rep(i,0,m) cin>>querys[i];

    rep(i,1,n + 1){
        vector<int> primes = factors(i);

        // cout<<i<<": ";
        // for(auto p : primes) cout<<p<<" ";
        // cout<<endl;

        order.push_back({i,primes});
    }

    sort(order.begin(), order.end(), comb);

    rep(i,0,m){
        cout<<order[querys[i] - 1].first<<endl;
    }
}

/*
1
2
4
8
6
10
3
9
5
7

*/