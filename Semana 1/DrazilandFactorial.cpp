#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;
vector<int> primes(10,0);

void primeFactor (int n ){
    for (int i = 2 ; i <= n ; i++){
        
        while (n % i == 0 && n > 0 ){
            //primes.push_back(i);
            primes[i]++;
            //cout<<i<<" ";
            n = n / i ;
        }
    }
}

int main(){
    int n; cin>>n;
    string numbers; cin>>numbers;

    sort(numbers.begin(), numbers.end());

    for(char number: numbers){
        int digit = number - '0';

        if(digit == 0 || digit == 1) continue;
        // if(digit == 5 || digit == 7){
        //     primes[digit]++;
        //     continue;
        // }
        //cout<<"--------- "<<digit<<" -----------\n";


        for(int i = 2; i <= digit; i++){
            //cout<<"--------- "<<i<<"\n";
            primeFactor(i);
        }

    }

    for(int i = 0; i<10; i++){
        cout<<i<<" "<<primes[i]<<endl;
    }

    primes[2] -= primes[3];

    for(int i = 0; i<primes[7]; i++) cout<<"7";
    for(int i = 0; i<primes[5]; i++) cout<<"5";
    for(int i = 0; i<primes[3]; i++) cout<<"3";
    for(int i = 0; i<primes[2]; i++) cout<<"2";
}