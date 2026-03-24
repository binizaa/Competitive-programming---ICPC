#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        vector<int>a;

        for (int i = 0; i < n; i++){
            int given;
            cin >> given;
            a.push_back(given);
        }

        bool extremeCase = true;

        for(auto num : a){
            if(num != -1) extremeCase = false;
        }

        if (extremeCase) a[0] = 0;

        int first = 1e9;

        for (int i = 0; i < a.size(); i++){

            if(a[i] != -1){
                first = min(first, i);
            }

            if(first > n || i == 0 || first == i) continue;
            a[i] = (a[i-1]+1) % m;  
        }

        for (int i = first - 1; i >= 0; i--){
            a[i] = (a[i + 1] - 1 + m)%m;
        }

        for(auto num: a) cout<<num<<" ";
        cout << endl;
    }
}

/*
4
5 10
1 2 3 4 5
4 10
7 -1 9 -1
6 7
5 -1 -1 1 2 3
6 10
5 -1 7 -1 9 0

1 2 3 4 5
7 8 9 0
5 6 0 1 2 3
5 6 7 8 9 0

*/

/*
1
5 5
-1 -1 1 2 -1
*/