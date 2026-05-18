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

void build() {
    fill(depth, depth + n + 1, -1);

    queue<int> q;
    q.push(1);
    depth[1] = 0;
    up[1][0]  = 1;         

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

int kth_ancestor(int v, int k) {
    for (int i = LOG - 1; i >= 0; i--)
        if (k >= (1 << i)) { v = up[v][i]; k -= (1 << i); }
    return v;
}

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

    cin >> n;
    int q; cin >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        add_edge(u, v);
    }

    build();   

    while (q--) {

        int u, v; cin >> u >> v;
        cout <<dist(u, v) << "\n";
    }

    return 0;
}
