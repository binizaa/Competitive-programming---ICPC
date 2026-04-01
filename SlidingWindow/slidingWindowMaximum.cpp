#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    //for(auto i : nums) cout<<i<<" ";

    deque<int> q;
    vector<int> result;

    rep(i,0,n){
        int last = last = nums[i];
        if(!q.empty())last = q.back();
        
        while(!q.empty() && last < nums[i]){
            
            q.pop_back();
            last = nums[i];
            if(!q.empty())last = q.back();
        }

        q.push_back(nums[i]);

        // for(auto j : q) cout<<j<<" ";
        // cout<<endl;

        if(i >= k){
            int first = q.front();
            if(first == nums[i - k]) q.pop_front();
        }

        if(i >= k - 1) result.push_back(q.front());

    }

    for(auto r : result) cout<<r<<" ";
    cout<<endl;

    return 0;
}

/* 
8 3
1 3 -1 -3 5 3 6 7
*/