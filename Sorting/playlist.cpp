#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> songs(n);
    rep(i, 0, n) cin >> songs[i];

    unordered_map<int, int> compress;
    compress.reserve(n);           
    compress.max_load_factor(0.25); 
    int idx = 0;
    rep(i, 0, n) {
        if(!compress.count(songs[i]))
            compress[songs[i]] = idx++;
        songs[i] = compress[songs[i]];
    }

    vector<int> arr(n, -1);
    int l = 0, maxi = 0;

    for(int r = 0; r < n; r++) {
        if(arr[songs[r]] > -1) {
            int dup_pos = arr[songs[r]];
            while(l <= dup_pos) {
                arr[songs[l]] = -1;
                l++;
            }
        }
        arr[songs[r]] = r;
        maxi = max(maxi, r - l + 1);
    }

    cout << maxi << endl;
}