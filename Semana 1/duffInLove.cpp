#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;

vector<long long> factores;

//ICPC
vector<long long> getFactors(long long n) {
    std::vector<long long> primos;
    if (n <= 1) return primos;

    for (long long i = 2; i <= std::sqrt(n); ++i) {
        while (n % i == 0) {
            primos.push_back(i); 
            n /= i;
        }
    }
    if (n > 1) primos.push_back(n);  
    return primos;
}

int main() {
    long long num;
    cin >> num;

    factores = getFactors(num);

    set<long long> uniquePrimes;

    for(auto factor : factores){
        //cout<<factor<<" ";
        uniquePrimes.insert(factor);
    }

    //cout<<endl;

    long long mult = 1;

    for(auto primes : uniquePrimes) mult *= primes;

    cout<<mult<<endl;

    return 0;
}