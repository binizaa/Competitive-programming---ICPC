#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

typedef long long ll;
#define rep(i,a,b) for(ll i=a; i<b; i++)

using namespace std;

struct type{
    int num;
    int index;
    bool type;
};

bool compare(type a, type b){
    return a.num < b.num;
}

int main(){
    int n; cin>>n;

    vector<type> sorted;
    
    rep(i,0,n){
        int a,b; cin>>a>>b;

        type A;
        A.index = i;
        A.num = a;
        A.type = true;

        type B;
        B.index = i;
        B.num = b;
        B.type = false;
        

        sorted.push_back(A);
        sorted.push_back(B);
    }

    sort(sorted.begin(), sorted.end(), compare);

    // rep(i,0,n*2) cout<<sorted[i].num<<" ";
    // cout<<endl;

    vector<int> prefixA(n*2);
    vector<int> prefixB(n*2);

    if(sorted[0].type){
        prefixA[0] = 0;
        prefixB[0] = -1;
    }else{
        prefixB[0] = 0;
        prefixA[0] = -1;
    }

    rep(i,1,n*2){
        if(sorted[i].type){
            //cout<<"a: ";
            prefixA[i] = prefixA[i-1] + 1;
            prefixB[i] = prefixB[i-1];
        }else{
            //cout<<"b: ";
            prefixB[i] = prefixB[i-1] + 1;
            prefixA[i] = prefixA[i-1];
        }

        //cout<<prefixA[i]<<" "<<prefixB[i]<<endl;
    }

    //cout<<"-------------"<<endl;

    // rep(i,0,n*2) cout<<prefixA[i]<<" ";
    // cout<<endl;
    // rep(i,0,n*2) cout<<prefixB[i]<<" ";
    // cout<<endl;
    // rep(i,0,n*2) cout<<sorted[i].type<<" ";

    // cout<<"\n-------------"<<endl;

    vector<int> resultA(n,0);
    vector<int> resultB(n,0);

    int mid = floor(n/2);

    rep(i,0,mid){
        resultA[i] = 1;
        resultB[i] = 1;
    }

    int maxA = -1;
    int maxB = -1;

    rep(i,0,mid + 1){
        int missing = n - 2*i;

        //cout<<i<<" "<<missing<<endl;

        maxA = max(maxA, prefixA[i+missing - 1]);
        maxB = max(maxB, prefixB[i+missing - 1]);
    }
    // cout<<"\n-------------"<<endl;
    // cout<<maxA<<" "<<maxB<<endl;

    rep(i,0,maxB + 1) resultB[i]=1;
    rep(i,0,maxA + 1) resultA[i]=1;

    rep(i,0,n) cout<<resultA[i];
    cout<<endl;
    rep(i,0,n) cout<<resultB[i];
    cout<<endl;
    
}

/*
4
9840 9920
9860 9980
9930 10020
10040 10090

*/