#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(){
    string burger;
    cin >> burger;
    
    long long nb, ns, nc;
    cin >> nb >> ns >> nc;
    
    long long pb, ps, pc;
    cin >> pb >> ps >> pc;
    
    long long r;
    cin >> r;
    
    long long cntB = 0, cntS = 0, cntC = 0;
    for(char c : burger){
        if(c == 'B') cntB++;
        if(c == 'S') cntS++;
        if(c == 'C') cntC++;
    }
    
    auto canMake = [&](long long mid) -> bool {
        long long cost = 0;
        long long needB = max(0LL, cntB * mid - nb);
        long long needS = max(0LL, cntS * mid - ns);
        long long needC = max(0LL, cntC * mid - nc);
        cost = needB * pb + needS * ps + needC * pc;
        return cost <= r;
    };
    
    long long l = 0, ri = 2e12; 
    while(l < ri){
        long long mid = (l + ri + 1) / 2;
        if(canMake(mid))
            l = mid;
        else
            ri = mid - 1;
    }
    
    cout << l << endl;
    return 0;
}