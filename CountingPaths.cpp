/*
Prequisite : Idea of BL, How to calculate LCA efficiently
We first calculate the LCA
use Binary Lifting for above purpose
We process all the queries
node (a) = + 1
node (b) = + 1
node (LCA(a, b)) = -2
and at the end we calculate the answer.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
vector<int> adj[MAXN + 1];
int parent[20][MAXN + 1];
int depth[MAXN + 1];
long long val[MAXN + 1];
int n, m;

/* DFS to set parent[0] and depth */
void dfs_init(int u, int p) {
    parent[0][u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs_init(v, u);
    }
}

/* Compute LCA using binary lifting */
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    // Lift a up to the same depth as b
    for (int i = 19; i >= 0; i--) {
        if (parent[i][a] && depth[parent[i][a]] >= depth[b])
            a = parent[i][a];
    }

    if (a == b) return a;

    // Lift both until parents differ
    for (int i = 19; i >= 0; i--) {
        if (parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }

    return parent[0][a];
}

/* DFS to accumulate values */
void dfs_sum(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_sum(v, u);
        val[u] += val[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    /* Root the tree at 1 */
    dfs_init(1, 0);

    /* Precompute parents */
    for (int i = 1; i < 20; i++) {
        for (int v = 1; v <= n; v++) {
            parent[i][v] = parent[i - 1][ parent[i - 1][v] ];
        }
    }

    /* Process paths */
    while (m--) {
        int a, b;
        cin >> a >> b;
        int c = lca(a, b);

        val[a]++;
        val[b]++;
        val[c] -= 2;
    }

    /* Accumulate values */
    dfs_sum(1, 0);

    /* Output result */
    for (int i = 1; i <= n; i++) {
        cout << val[i] << " ";
    }
    cout << "\n";

    return 0;
}
