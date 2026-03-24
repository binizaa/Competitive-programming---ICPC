//https://codeforces.com/group/tykB2ee0Ff/contest/680406/problem/G

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

int main(){
    int n; cin>>n;
    int cnt = 1;

    while(true){
        int formula = (cnt*(cnt+1))/2;
        if(n <=formula){
            cout<<cnt<<endl;
            if(cnt%2==0) cout<<"John"<<endl;
            else cout<<"Jane"<<endl;
            break;
        }

        cnt++;
    }
}