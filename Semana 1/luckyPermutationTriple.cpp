#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(){
    int n; cin>>n;

    if(n%2 == 0){
        cout<<-1<<endl;
        return 0;
    }

    if(n == 1){
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        return 0;
    }

    vector<int> set1(n), set2(n), set3(n);

    for(int i = 0; i < n; i++) set1[i] = i;

    set2[n - 2] = 0;
    set2[n - 1] = n - 1;
    for(int i = 0; i < n - 2; i++) set2[i] = n - i - 2;

    int index = 0;

    for(int i = 2; i < n; i+=2){
        set3[index] = i;
        index++;
    }

    for(int i = 1; i < n; i+=2){
        set3[index] = i;
        index++;
    }

    set3[n-1] = 0;

    for(auto i : set2) cout<<i<<" ";
    cout<<endl;
    for(auto i : set3) cout<<i<<" ";
    cout<<endl;
    for(auto i : set1) cout<<i<<" ";
    cout<<endl;
}

// 1 4 3 2 0
// 1 0 2 4 3
// 2 4 0 1 3
