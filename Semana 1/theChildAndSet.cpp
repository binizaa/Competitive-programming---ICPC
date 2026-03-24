#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;
vector<int> number = {16,8,4,2,1};

vector<int>  isPossible(int sum, vector<int> cnt, vector<int> acumulado){
    if(sum == 0) return acumulado;
    
    for(int i = 0; i < 5; i++){
        if(cnt[i] == 0) continue;
        if(sum < number[i]) continue;

        cnt[i]--;
        acumulado[i]++;

        return isPossible(sum-number[i], cnt, acumulado);
    }

    return {};
}

int main(){
    int sum, limit; cin>>sum>>limit;
    vector<int> cnt(5);

    int one = limit >= 1 ? 1 : 0;
    int two = limit >= 2 ? 1 : 0;
    int four = limit >= 4 ? 1 : 0;
    int eight = limit >= 8 ? 1 : 0;
    int six = limit >= 16 ? 1 : 0;

    one += (limit - 1)/2;
    two += (limit - 2)/4;
    four += (limit - 4)/8;
    eight += (limit - 8)/16;
    six += (limit - 16)/32;

    cnt[4] = one;
    cnt[3] = two;
    cnt[2] = four;
    cnt[1] = eight;
    cnt[0] = six;

    vector<int> diff = {32,16,8,4,2};

    // cout<<one<<" "<<two<<" "<<four<<" "<<eight<<" "<<six<<endl;

    vector<int> result = isPossible(sum, cnt, vector<int>(5));
    
    if(result.size() == 0){
        cout<<-1<<endl;
        return 0;
    }
    
    int size = 0;

    for(int i = 0; i < 5; i++){
        size += result[i];
    }

    cout<<size<<endl;

    for(int i = 0; i < 5; i++){
        //cout<<number[i]<<": ";
        for(int j = 0; j < result[i]; j++){
            cout<<number[i] + j*diff[i]<<" ";
        }
        //cout<<endl;
    }
}