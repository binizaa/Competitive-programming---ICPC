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

    long long last = array[n - 1];
    long long cnt = array[n - 1];


    for(int i = n-2; i >= 0; i--){
        // cout<<cnt<<" ";
        cnt = (array[i] & (1 + last) ) + cnt;
        last = (array[i] & (1 + last));
        // cout<<cnt<<endl;
    }

    cout<<cnt<<endl;
}

int main(){
    //ICPC
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // int t; cin>>t;

    // while(t--) solve();

    cout<<(7&11)<<endl;

}

/*
2
3
7 11 9
4
11 9 6 11
*/