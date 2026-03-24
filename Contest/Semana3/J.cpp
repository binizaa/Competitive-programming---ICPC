//https://codeforces.com/gym/101532/problem/J
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

int MOD = 1e9 + 7;

void solve(){
     int n; cin>>n;

     vector<long long> array(n); 

    for(int i = 0; i < n; i++) cin>>array[i];

    long long cnt = array[n - 1];


    for(int i = n-2; i >= 0; i--){
        cnt = ((array[i] * (1 + cnt) )+ cnt)%MOD;
    }

    cout<<cnt%MOD<<endl;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; cin>>t;

    while(t--) solve();
}

/*
3
3
1 2 3
2
3 5
1
4512
*/