#https://codeforces.com/gym/104990/problem/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;
#define rep(i,a,b) for(long long i=a; i<b; i++)
long long MOD = 1e9 + 7;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<vector<long long>> multiplicar(vector<vector<long long>> a, vector<vector<long long>> b) {
    int m = a.size();
    vector<vector<long long>> temp(m, vector<long long>(m, 0));
    for (long long i = 0; i < m; i++)
        for (long long j = 0; j < m; j++)
            for (long long z = 0; z < m; z++)
                temp[i][j] = (temp[i][j] + a[i][z] * b[z][j]) % MOD;
    return temp;
}

vector<vector<long long>> powM(vector<vector<long long>> a, int n) {
    int m = a.size();
    if (n == 0) {
        vector<vector<long long>> identity(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) identity[i][i] = 1;
        return identity;
    }
    if (n % 2 == 0) {
        auto half = powM(a, n / 2);  
        return multiplicar(half, half);
    }
    return multiplicar(powM(a, n - 1), a);
}

int main() {
    long long n, m; cin >> n >> m;
    if (n == 1) {
        cout << m % MOD << endl;
        return 0;
    }
    vector<vector<long long>> graph(m, vector<long long>(m, 0));
    for (long long i = 1; i <= m; i++)
        for (long long j = 1; j <= m; j++)
            if (gcd(i, j) == 1)
                graph[i-1][j-1] = 1;

    vector<vector<long long>> result = powM(graph, n - 1);

    // for(auto list: result){
    //     for(auto v : list) cout<< v<<" ";
    //     cout<<endl;
    // }   

    long long cnt = 0;
    rep(i, 0, m)
        rep(j, 0, m)
            cnt = (cnt + result[i][j]) % MOD;
    cout << cnt % MOD << endl;
}