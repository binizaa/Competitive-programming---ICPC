#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;

vector<long long> getFactors(long long n) {
    std::vector<long long> factores;
    if (n <= 0) return factores;

    // Iterar solo hasta la raíz cuadrada de n
    for (long long i = 1; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            factores.push_back(i); // Agregar el factor i
            if (i*i != n) {
                factores.push_back(n / i); // Agregar el factor par n/i
            }
        }
    }
    std::sort(factores.begin(), factores.end());
    return factores;
}

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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int a,b; cin>>a>>b;

    if(a == b){
        cout<<0<<endl;
        return 0;
    }

    int g = gcd(a,b);
    cout<<g<<endl;
    int d1 = a/g, d2 = b/g;
    cout<<d1<<" "<<d2<<endl;
    
    vector<long long> listPrimes1 = getFactors(a/g);
    vector<long long> listPrimes2 = getFactors(d2);

    for(auto prime : listPrimes1) cout<<prime<<" ";
    cout<<endl;
    for(auto prime : listPrimes2) cout<<prime<<" ";
}