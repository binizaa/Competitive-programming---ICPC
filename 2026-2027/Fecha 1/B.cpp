//https://codeforces.com/gym/106495/problem/B

#include <iostream>

#define rep(i,a,b) for(long long i=a; i<b; i++)

using namespace std;

string latex(string old){
    string newN = "";
    if(old.size() < 5) return old;

    int last;

    for(int i = old.size() - 1; i >=0; i--){
        if(old[i] != '0'){
            last = i;
            break;
        }
    }

    int zeros = old.size() - last - 1;
    if( 4 > zeros) return old;

    if(last == 0){
    
        if(old[0] != '1'){
            newN = old[0];
            newN += "\\cdot10^{" + to_string(zeros) + "}" ;
            return newN;
        }

        newN = "10";
        
        newN += "^{" + to_string(old.size() - 1) + "}";
        return newN;
    }

    newN = old[0];
    newN += ".";

    rep(i,1,last + 1) newN += old[i];

    //ICPC
    newN += "\\cdot10^{" + to_string(old.size() - 1) + "}" ;

    return newN;
}

bool isNumber(string str){
    rep(i,0,str.size()){
        if(str[i] < 48 || str[i] > 57) return false;
    }

    return true;
}

void solve(){
    string str;
    getline(cin, str);

    string word; word = "";

    string newStr = "";

    rep(i,0,str.size()){
        if(str[i] == ' '){
            if(isNumber(word)){
                word = latex(word);
            }

            if(newStr.size() != 0) newStr += ' ';

            newStr += word;
            word = "";
        }else word += str[i];
    }

    if(isNumber(word)){
        word = latex(word);
    }
    if(newStr.size() != 0) newStr += ' ';
    newStr += word;

    cout<<newStr<<endl;
}

int main(){
    int t; cin>>t;
    cin.ignore();

    while(t--) solve();
}