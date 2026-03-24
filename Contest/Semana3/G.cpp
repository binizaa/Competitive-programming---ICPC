//https://codeforces.com/gym/101532/problem/G

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;

void solve(){
    int n; cin>>n;

    vector<int> a(n);

    vector<int> prefix(n);
    vector<int> subfix(n);

    for(int i = 0; i<n; i++) cin>>a[i];

    prefix[0] = a[0];

    for(int i = 1; i<n; i++){
        prefix[i] = max(prefix[i-1], a[i]);
    }

    subfix[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        subfix[i] = min(subfix[i+1], a[i]);
    }

    // for(auto num: a) cout<<num<<" ";
    // cout<<endl;

    // for(auto num: prefix) cout<<num<<" ";

    // cout<<endl;
    
    // for(auto num: subfix) cout<<num<<" ";

    int magicIndex = 0;

    for(int i = 1; i<n-1; i++){
        if(prefix[i] == subfix[i]) magicIndex++;
    }

    cout<<magicIndex<<endl;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; cin>>t;

    while(t--) solve();
}


/*
2
8
2 1 3 4 6 5 7 9
6
4 2 7 9 8 10

*/