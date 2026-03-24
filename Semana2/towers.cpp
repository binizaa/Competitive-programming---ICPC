#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

struct nums{
    int number;
    stack<int> list;
};

int main(){
    vector<queue<int>> towers(10e4);
    vector<bool> exist(10e4,0);

    int n, k; cin>>n>>k;
    int mini = 10e4;
    int maxi = 1;

    for(int i = 1; i <= n ; i++){
        int aux; cin>>aux;

        towers[aux].push(i);

        maxi = max(maxi, aux);
        mini = min(mini, aux);
    }

    // for(auto& alturas:towers){
    //     if(!alturas.empty()){
    //         while(!alturas.empty()){
    //             cout << alturas.front() << " ";
    //             alturas.pop();
    //         }
    //         cout<<endl;
    //     }
    // }

    int numExchange = 0;
    vector<pair<int,int>> exchanges;

    while(maxi - mini > 1 && k>0 ){
        k--;
        numExchange++;
        pair<int,int> exc;

        int towerMaxi = towers[maxi].front();
        towers[maxi].pop();
        //cout<<"Torre maxi "<< towerMaxi<<endl;
        
        towers[maxi - 1].push(towerMaxi);
        exc.first = towerMaxi;

        if(towers[maxi].empty()) maxi--;

        ///
        int towerMini = towers[mini].front();
        towers[mini].pop();
        //cout<<"Torre mini "<< towerMini<<endl;
        
        towers[mini + 1].push(towerMini);
        exc.second = towerMini;

        if(towers[mini].empty()) mini++;

        //cout<<mini<<" "<<maxi<<endl;

        exchanges.push_back(exc);
    }

    cout<<maxi-mini<<" "<<numExchange<<endl;

    for(auto exchange: exchanges){
        cout<<exchange.first<<" "<<exchange.second<<endl;
    }

}