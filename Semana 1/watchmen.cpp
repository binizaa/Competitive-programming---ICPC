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

    vector<pair<int,int>> watchmen(n);

    for(int i = 0; i < n; i++){
        cin>>watchmen[i].first>>watchmen[i].second;
    }

    sort(watchmen.begin(), watchmen.end());

    //Contar xs 
    //Falta considerar el no contado cada vez que cambia
    int xs = 0;
    int same = 0;
    cout<<"------------\n";

    for(int i = 0; i < n - 1; i++){
        cout<<watchmen[i].first<<" "<<watchmen[i].second<<endl;
        if(watchmen[i].first == watchmen[i + 1].first){
            xs++;
        }

        if(watchmen[i].first == watchmen[i + 1].first && watchmen[i].second == watchmen[i + 1].second){
            same++;
        }
    }

    //if(xs>0) xs++;

    //Contar ys
    cout<<"------------\n";

    sort(watchmen.begin(), watchmen.end(), [](const auto &a, const auto &b) {
        return a.second < b.second; 
    });

    int ys = 0;

    for(int i = 0; i < n - 1; i++){
        cout<<watchmen[i].first<<" "<<watchmen[i].second<<endl;
        if(watchmen[i].second == watchmen[i + 1].second) ys++;
    }

    //if(xs>0) xs++;
    cout<<"------------\n";

    cout<<xs<<" "<<ys<<" "<<same<<endl;
}

// 3
// 1 1
// 7 5
// 1 5