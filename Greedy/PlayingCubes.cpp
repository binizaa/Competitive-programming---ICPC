//https://codeforces.com/contest/257/problem/B

#include <iostream>

using namespace std;

int main(){
    int n,m; cin>>n>>m;

    if(n==1 || m==1){
        cout<<max(n,m) - 1<<1<<endl;
    }

    int mini = min(n,m);

    int v = mini + 1;
    int p = mini;

    int diff = max(n,m) - mini;

    p = diff;

    cout<<p<<" "<<v<<endl;
}