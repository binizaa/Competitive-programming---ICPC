#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k = 3, a, b; cin >> n >> a >> b;
    vector<int> prefixSum(n);


    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];

        if(i == 0) prefixSum[i] = nums[i];
        else prefixSum[i] = prefixSum[i- 1] + nums[i];
    }

    deque<pair<int,int>> q;
    int maxi = -1e9;    

    rep(i, 0, min(n, b)) {
        cout << "i=" << i << " nums[i]=" << nums[i] 
            << " prefixSum[i]=" << prefixSum[i] << "\n";

        pair<int,int> diff = make_pair(prefixSum[i], i + 1);

        while (!q.empty() && q.back().first < diff.first) {
            cout << "  Eliminando de deque: val=" << q.back().first << "\n";
            q.pop_back();
        }

        q.push_back(diff);
        maxi = max(diff.first, maxi);

        cout << "  Deque actual: ";
        for (auto& p : q) cout << "(" << p.first << "," << p.second << ") ";
        cout << "\n";
    }


    rep(i,0,n - a){

        while(!q.empty() && q.back().second - 1 < a){
            q.pop();
        }

        pair<int, int> next = q.back();

        q.clear();

        q.push_back(next.first - )
    }


    return 0;
}

/* 
8 1 2
-1 3 -2 5 3 -5 2 2
*/