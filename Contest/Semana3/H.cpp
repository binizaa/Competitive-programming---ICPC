// https://codeforces.com/group/tykB2ee0Ff/contest/673902/problem/H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;

void solve(){
    int n, m; cin>>n>>m;

    vector<string>image(n);

    int cnt1 = 0;
    int marco0 = 0;

    for(int i = 0; i<n; i++){
        cin>>image[i];
        for(int j = 0; j<m; j++){

            if(image[i][j] == '1') cnt1++;
        }
    }

    for(int i = 0; i<n; i++){        
        if(image[i][0] == '0') marco0++;
        else cnt1--;
    }

    for(int i = 0; i<n; i++){
        if(image[i][m-1] == '0') marco0++;
        else cnt1--;
    }

    for(int j = 1; j<m-1; j++){
        if(image[0][j] == '0') marco0++;
        else cnt1--;

        if(image[n-1][j] == '0') marco0++;
        else cnt1--;
    }

    if(marco0 == 0){
        cout<<0<<endl;
    }else if(marco0 <= cnt1) cout<<marco0<<endl;
    else cout<<-1<<endl;
}

int main(){
    int t; cin>>t;

    while(t--) solve();
}
/*

3
3 3
111
101
111
4 4
1111
0111
1000
1111
4 5
10101
01010
10101
01010

*/
