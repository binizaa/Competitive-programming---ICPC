#include <iostream>
#include <vector>
#include <map>
#include <deque>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> nums(n + 1);
    map<int,int> frecuency;
    deque<pair<int,int>> dq;
    rep(i,1,n + 1) cin >> nums[i];

    int distintos = 0;
    int l = 1;
    int maxiL = 0;
    int maxL  = 0;
    int maxR  = 0;

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

        if(maxiL <= i - l + 1){
            maxiL = i - l + 1;
            maxL = l;
            maxR = i;
        }
    }

    cout << maxL << " " << maxR << endl;
}