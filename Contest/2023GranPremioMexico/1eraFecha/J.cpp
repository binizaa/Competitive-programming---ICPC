//https://codeforces.com/group/tykB2ee0Ff/contest/680406/problem/J


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

typedef long long ll;
#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int MOD = 1e9+7;

int main(){
    int n, q; cin>>n>>q;

    vector<int> substances(n);

    rep(i,0,n) cin>>substances[i];

    vector<int> prefixSum(n);

    prefixSum[0] = substances[0];

    rep(i,1,n) prefixSum[i] = prefixSum[i-1] + substances[i];

    rep(i,0,q){
        int l,r; cin>>l>>r;
        int cnt = 0;

        rep(i,l-1,r - 1){
            cnt += substances[i]*(prefixSum[r-1] - prefixSum[i])%MOD ;
            //cout<<substances[i]<<" "<<prefixSum[r-1]<<" "<< prefixSum[i]<<endl;
        }

        cout<<cnt%MOD<<endl;
    }
}

/*
5 3
1 2 3 4 5
1 2
1 5
3 5

2
85
47

1 5
*/