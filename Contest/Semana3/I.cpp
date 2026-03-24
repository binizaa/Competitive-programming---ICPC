//https://codeforces.com/gym/101532/problem/I
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct step{
    int index;
    int step = 0;
};

int bfs(vector<vector<int>> graph, int end){
    vector<bool> visited(end + 1, false);

    queue<step> q;
    visited[0] = true;

    step start; start.index = 0;
    q.push(start);

    while(!q.empty()){
        step current = q.front();
        q.pop();

        if(current.index == end) return current.step;

        for (int neighbor : graph[current.index]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;

                step next;
                next.index = neighbor;
                next.step = current.step + 1;
                q.push(next);
            }
        }
    }

    return -1;
}

void solve(){
    int n; cin>>n;
    vector<vector<int>> graph(n);

    vector<int> numbers(1e6, -1);

    for(int i = 0; i<n; i++){
        int aux; cin>>aux;

        if(numbers[aux] != -1){
            // graph[i].push_back(numbers[aux]);
            graph[numbers[aux]].push_back(i);
        }
        numbers[aux] = i;

        if(i<n-1) graph[i].push_back(i+1);
    }

    // int cnt = 0;

    // for(auto list: graph){
    //     cout<<cnt<<": ";
    //     for(auto index : list){
    //         cout<<index<<" ";
    //     }
    //     cout<<endl;
    //     // cout<<list.size()<<endl;
    //     cnt++;
    // }

    int result = bfs(graph, n - 1);

    cout<<result<<endl;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t; cin>>t;

    while(t--) solve();
}

/*
3
6
9 2 4 7 1 5
5
1 2 1 1 4
6
1 2 3 1 3 2
*/