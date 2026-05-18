#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(long long i=a; i<b; i++)

struct Group {
    long long continua;
    long long index;
    char ch;
};

bool comp(Group a, Group b){
    return a.continua > b.continua;
}

int main(){
    long long n; cin>>n;

    vector<long long> as(n);
    rep(i,0,n) cin>>as[i];
    string original; cin >> original;

    vector<Group> order;
    vector<Group> equals;
    long long cont = 1;

    string str; str = "";

    rep(i,0,original.size()){
        if(original[i] != '=') str += original[i];
    }

    // Solo iguales

    if(str.size() == 0){

        long long sum = 0;

        rep(i,0,n) sum += as[i];

        cout<<sum<<endl;
        
        rep(i,0,n){
            cout<<1<<" ";
        }

        return 0;
    }

    rep(i, 1, str.size()){
        if(str[i-1] == str[i]) cont++;
        else {
            order.push_back({cont, i - cont, str[i-1]});
            cont = 1;
        }
    }
    order.push_back({cont, (long long)str.size() - cont, str[str.size()-1]});

    sort(order.begin(), order.end(), comp);

    vector<long long> numbers(str.size() + 1, 0);

    rep(i,0,order.size()){
        long long index = order[i].index;

        if(order[i].ch == '>'){
            for(long long j = order[i].continua + 1; j > 0; j--){
                numbers[index] = max(numbers[index], j);
                index++;
            }
            continue;
        }
        if(order[i].ch == '<'){
            for(long long j = 1; j <= order[i].continua + 1; j++){
                numbers[index] = max(numbers[index], j);
                index++;
            }
            continue;
        }

    }


    vector<long long> result;

    result.push_back(numbers[0]);

    long long index = 0;


    rep(i,0,original.size()){
        if(original[i] != '='){
            index++;
        }

        result.push_back(numbers[index]);
    }

    long long sum = 0;

    rep(i,0,n) sum += as[i]*result[i];

    cout<<sum<<endl;

    for(auto i : result) cout<<i<<" ";

    return 0;
}