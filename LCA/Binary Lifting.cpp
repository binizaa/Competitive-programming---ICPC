/*
  Binary Lifting — raíz fija en nodo 1
  Complejidad: O(n log n) construcción, O(log n) por consulta
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG  = 17;

int  n;
int  depth[MAXN];
int  up[MAXN][LOG];
vector<int> adj[MAXN];

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Siempre enraíza en nodo 1 — no necesitas conocer la raíz
void build() {
    fill(depth, depth + n + 1, -1);

    queue<int> q;
    q.push(1);
    depth[1] = 0;
    up[1][0]  = 1;          // la raíz es su propio padre

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int w : adj[v]) {
            if (depth[w] == -1) {
                depth[w] = depth[v] + 1;
                up[w][0] = v;
                q.push(w);
            }
        }
    }

    for (int k = 1; k < LOG; k++)
        for (int v = 1; v <= n; v++)
            up[v][k] = up[ up[v][k-1] ][k-1];
}

// Altura del nodo v (distancia a la raíz)
int get_depth(int v) {
    return depth[v];
}

// k-ésimo ancestro de v
int kth_ancestor(int v, int k) {
    for (int i = LOG - 1; i >= 0; i--)
        if (k >= (1 << i)) { v = up[v][i]; k -= (1 << i); }
    return v;
}

// LCA de u y v — retorna {nodo, profundidad}
pair<int,int> lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = kth_ancestor(u, depth[u] - depth[v]);
    if (u == v) return {u, depth[u]};
    for (int k = LOG - 1; k >= 0; k--)
        if (up[u][k] != up[v][k]) { u = up[u][k]; v = up[v][k]; }
    return {up[u][0], depth[up[u][0]]};
}

int dist(int u, int v) {
    auto [anc, d] = lca(u, v);
    return depth[u] + depth[v] - 2 * d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Entrada: solo n y las n-1 aristas — sin raíz
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        add_edge(u, v);
    }

    build();   // enraíza en nodo 1 automáticamente

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;

        if (type == 1) {
            int v; cin >> v;
            cout << "Nodo " << v << " | altura = " << get_depth(v) << "\n";
        }
        else if (type == 2) {
            int u, v; cin >> u >> v;
            auto [anc, d] = lca(u, v);
            cout << "LCA(" << u << "," << v << ") = " << anc
                 << " | prof = " << d
                 << " | dist = " << dist(u, v) << "\n";
        }
        else {
            int v, k; cin >> v >> k;
            cout << "Ancestro " << k << " de " << v
                 << " = " << kth_ancestor(v, k) << "\n";
        }
    }

    return 0;
}

/*
  ── Ejemplo de entrada ──────────────────────────────────────────

  9
  1 2
  1 3
  2 4
  2 5
  3 6
  3 7
  4 8
  4 9
  3
  1 8
  2 8 6
  2 9 7

  ── Salida ──────────────────────────────────────────────────────

  Nodo 8 | altura = 3
  LCA(8,6) = 1 | prof = 0 | dist = 5
  LCA(9,7) = 1 | prof = 0 | dist = 4
*/