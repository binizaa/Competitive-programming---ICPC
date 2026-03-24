#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;

//ICPC
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

long long lcm(long long a, long long b){
    return (a*b)/gcd(a,b);
}

int main(){
    long long a,  b; cin>>a>>b;

    long long lcmm = lcm(a,b);
    //cout<<lcmm<<endl;

    long long timesA = lcmm/a -1;
    long long timesB = lcmm/b -1;

    if(a > b){
        timesA++;
    }else timesB++;

    if(timesA == timesB) cout<<"Equal"<<endl;
    else if(timesA > timesB) cout<<"Dasha"<<endl;
    else cout<<"Masha"<<endl;
}