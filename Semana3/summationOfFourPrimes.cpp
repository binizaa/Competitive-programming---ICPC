#include <iostream>
#include <vector>
using namespace std;

const int LIMITE = 10000000;
vector<bool> es_primo_arr(LIMITE + 1, true);

void criba() {
    es_primo_arr[0] = es_primo_arr[1] = false;
    for (int p = 2; (long long)p * p <= LIMITE; p++) {
        if (es_primo_arr[p])
            for (int i = p * p; i <= LIMITE; i += p)
                es_primo_arr[i] = false;
    }
}

pair<int,int> goldbach(int n) {
    for (int p = 2; p <= n / 2; p++) {
        if (es_primo_arr[p] && es_primo_arr[n - p])
            return {p, n - p};
    }
    return {-1, -1}; // no debería ocurrir para n >= 4
}

void solve(int n) {
    if (n <= 7) {              
        cout << "Impossible.\n";
        return;
    }
    if (n % 2) {               
        pair<int,int> p = goldbach(n - 5);
        cout << 2 << " " << 3 << " " << p.first << " " << p.second <<endl;
    } else {                  
        pair<int,int> p = goldbach(n - 4);
        cout << 2 << " " << 2 << " " << p.first << " " << p.second <<endl;
    }
}

int main() {
    criba();
    int n;
    while (cin >> n)
        solve(n);
}