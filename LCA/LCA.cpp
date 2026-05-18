#include <bits/stdc++.h>
using namespace std;

// ─── Sparse Table (Range Minimum Query en O(1)) ───────────────────────────────

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

// ─── LCA con Euler Tour ───────────────────────────────────────────────────────

struct LCA {
    int n;
    int tourIndex = 0;

    vector<long long> nodeDepth;   // profundidades en el Euler tour
    vector<int> nodeOrder;         // índices de nodos en el Euler tour
    vector<int> last;              // última aparición de cada nodo en el tour

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
            visit(node, depth);   // visita al volver (Euler tour)
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

// ─── Main ─────────────────────────────────────────────────────────────────────

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 17;
    vector<vector<int>> adj(n);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);  addEdge(0, 2);
    addEdge(1, 3);  addEdge(1, 4);
    addEdge(2, 5);  addEdge(2, 6);  addEdge(2, 7);
    addEdge(3, 8);  addEdge(3, 9);
    addEdge(5, 10); addEdge(5, 11);
    addEdge(7, 12); addEdge(7, 13);
    addEdge(11, 14); addEdge(11, 15); addEdge(11, 16);

    LCA lca(n, adj, /* root= */ 0);

    cout << "LCA(13, 14) = " << lca.query(13, 14) << "\n"; // esperado: 7
    cout << "LCA(9, 11)  = " << lca.query(9, 11)  << "\n"; // esperado: 0
    cout << "LCA(12, 12) = " << lca.query(12, 12) << "\n"; // esperado: 12

    return 0;
}