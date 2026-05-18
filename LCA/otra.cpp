#include <bits/stdc++.h>
using namespace std;

//ICPC
struct MinSparseTable {
    int n, P;
    vector<int> log2_table;
    vector<vector<long long>> dp;
    vector<vector<int>> it;

    MinSparseTable() {}

    MinSparseTable(const vector<long long>& v) {
        n = v.size();
        P = __lg(n);  // floor(log2(n))
        dp.assign(P + 1, vector<long long>(n));
        it.assign(P + 1, vector<int>(n));
        log2_table.resize(n + 1);

        for (int i = 0; i < n; i++) {
            dp[0][i] = v[i];
            it[0][i] = i;
        }

        log2_table[1] = 0;
        for (int i = 2; i <= n; i++)
            log2_table[i] = log2_table[i / 2] + 1;

        for (int p = 1; p <= P; p++) {
            for (int i = 0; i + (1 << p) <= n; i++) {
                long long L = dp[p-1][i];
                long long R = dp[p-1][i + (1 << (p-1))];
                dp[p][i] = min(L, R);
                it[p][i] = (L <= R) ? it[p-1][i] : it[p-1][i + (1 << (p-1))];
            }
        }
    }

    // Retorna el índice del mínimo en [l, r]
    int queryIndex(int l, int r) {
        int p = log2_table[r - l + 1];
        long long L = dp[p][l];
        long long R = dp[p][r - (1 << p) + 1];
        return (L <= R) ? it[p][l] : it[p][r - (1 << p) + 1];
    }
};

//ICPC
struct LCA {
    int n;
    int tourIndex = 0;

    vector<long long> nodeDepth;   
    vector<int> nodeOrder;         
    vector<int> last;              

    MinSparseTable sparseTable;

    LCA(int n, const vector<vector<int>>& adj, int root = 0) : n(n) {
        int eulerSize = 2 * n - 1;
        nodeDepth.resize(eulerSize);
        nodeOrder.resize(eulerSize);
        last.resize(n);

        dfs(adj, root, -1, 0);
        sparseTable = MinSparseTable(nodeDepth);
    }

    void dfs(const vector<vector<int>>& adj, int node, int parent, long long depth) {
        visit(node, depth);
        for (int child : adj[node]) {
            if (child == parent) continue;
            dfs(adj, child, node, depth + 1);
            visit(node, depth);   
        }
    }

    void visit(int node, long long depth) {
        nodeOrder[tourIndex] = node;
        nodeDepth[tourIndex] = depth;
        last[node] = tourIndex;
        tourIndex++;
    }

    // Retorna el índice del LCA de u y v
    int query(int u, int v) {
        int l = min(last[u], last[v]);
        int r = max(last[u], last[v]);
        int i = sparseTable.queryIndex(l, r);
        return nodeOrder[i];
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin>>n>>q;
    vector<vector<int>> adj(n);

    for(int i = 1; i < n; i++ ){
        int aux,two; cin>>aux;
        //addEdge(aux, i);
        adj[aux - 1].push_back(two - 1);
        adj[two - 1].push_back(aux - 1);
    }

    vector<pair<int,int>> queries(q);

    for(int i = 0; i < q; i++) 
        cin>>queries[i].first>> queries[i].second;

    LCA lca(n, adj, /* root= */ 0);


    for(int i = 0; i < q; i++){
        cout << lca.query(queries[i].first-1, queries[i].second-1) + 1 << "\n";
    }

    return 0;
}