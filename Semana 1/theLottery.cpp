//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1266

#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n; 
    int m;
    bool es_primero = true; 

    while (cin >> n >> m) {

        if (!es_primero) {
            cout << endl;
        }
        es_primero = false;

        vector<int> randoms(m); 
        for(int i = 0; i < m; i++) cin >> randoms[i];

        vector<bool> precal(n + 1, false);

        for(auto random : randoms) {
            if (random <= 0 || random > n) continue; 
            if (precal[random]) continue;

            for (long long i = random; i <= n; i += random) {
                precal[i] = true;
            }
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(!precal[i]) {
                cnt++;
            }
        }

        cout << cnt; 
    }

    return 0;
}