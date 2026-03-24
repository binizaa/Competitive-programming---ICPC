//https://codeforces.com/group/tykB2ee0Ff/contest/680406/problem/A


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

typedef long long ll;
#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int main(){
    int n; cin>>n;

    set<string> uniques;
    vector<string>names(n);

    rep(i,0,n){
        int cnt; cin>>cnt;
        cin.ignore();

        getline(cin, names[i]);
    }

    for(auto name: names){
        //cout<<name<<endl;


        string unique = "";

        rep(j, 0, name.size()) {
            if (j == 0 && name[j] != ' ') {
                unique += name[j];
            } else if (j > 0 && name[j-1] == ' ' && name[j] != ' ') {
                unique += name[j];
            }
        }

        //cout<<unique<<endl;
        uniques.insert(unique);
    }

    cout<<uniques.size()<<endl;
}
/*
2
2 ivan ramirez
2 franco borquez

*/