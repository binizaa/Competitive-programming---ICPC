// https://cses.fi/problemset/task/2428

#include <iostream>
#include <vector>
#include <map>
#include <deque>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)

long long countSubarrays(int n, int k) {
    k = min(k, n); 
    return (long long)k * n - (long long)k * (k - 1) / 2;
}

int main(){
    int n,k; cin>>n>>k;

    int lessK = countSubarrays(n,k);
    int moreK = 0;

    vector<int> nums(n + 1);
    map<int,int> frecuency;
    deque<pair<int,int>> dq;
    rep(i,1,n + 1) cin >> nums[i];

    int distintos = 0;
    int l = 1;
    int maxiL = 0;

    rep(i,1,n + 1){
        if(frecuency[nums[i]] == 0) distintos++;
        dq.push_back({nums[i], i});
        frecuency[nums[i]]++;

        while (!dq.empty() && distintos > k) {
            auto [val, pos] = dq.front();
            dq.pop_front();
            frecuency[val]--;
            if (frecuency[val] == 0) {
                distintos--;
            }
        }
        l = dq.empty() ? i + 1 : dq.front().second;

        if(k < i - l + 1){
            moreK++;
        }
    }

    //cout<<lessK<<" "<<moreK<<endl;

    cout<<lessK + moreK<<endl;
}