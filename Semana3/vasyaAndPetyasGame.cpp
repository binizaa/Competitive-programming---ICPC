//https://codeforces.com/contest/577/problem/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

typedef long long ll;
#define rep(i,a,b) for(ll i=a; i<b; i++)

using namespace std;

set<ll> result;

vector<long long> getFactors(long long n) {
    std::vector<long long> primos;
    if (n <= 1) return primos;

    for (long long i = 2; i <= std::sqrt(n); ++i) {
        while (n % i == 0) {
            if(!primos.empty()){
                if(primos[primos.size() - 1]%i == 0){
                    primos.push_back(i*primos[primos.size() - 1]); 
                }else{
                    primos.push_back(i); 
                }
            }else{
                primos.push_back(i); 
            } 
            
            n /= i;
        }
    }
    if (n > 1) primos.push_back(n);  
    return primos;
}

int main(){
    int n; cin>>n;

    for(int i = 1; i <= n; i++){
        vector<ll> factors = getFactors(i);

        for(auto f:factors) result.insert(f);
    }

    cout<<result.size()<<endl;
    for(auto s: result) cout<<s<<" ";
    cout<<endl;

}

/*
1 -> 1
2 -> 1 2 4
3 ->  1 3
4 -> 1 2 4

1 2 3 4


1 -> 1
2 -> 1 2 4
3 ->  1 3
4 -> 1 2 4
5 -> 1 5
6 -> 1 2 3 6

2 3 4 5
*/