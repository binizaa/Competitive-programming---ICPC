//https://codeforces.com/contest/402/problem/C
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

void solve(){
    int n, p; cin>>n>>p;

    int cnt = 0;
    int cntV = 2*n + p;

    rep(i,1,n){
        rep(j,i+1,n+1){

            if(cntV > cnt){
                //cout<<cnt<<": ";
                cout<<i<<" "<<j<<endl;
                cnt++;
            }else break;
            
        }
    }
}

int main(){
    int t; cin>>t;

    while(t--) solve();
}