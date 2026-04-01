// https://codeforces.com/contest/227/problem/C

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define rep(i,a,b) for(ll i=a; i<b; i++)

// ICPC
long long modpow(long long x, long long n, long long m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,m; cin>> n>> m;

    long long result = modpow(3,n, m);

    if(result == 0) result = m - 1;
    else result -=1;

    // cout<<modpow(3,n, m) - 1<<endl;

    cout<<result<<endl;
}