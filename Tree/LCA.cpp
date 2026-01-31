#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;

void dfs(int u, int parent)
{
    up[u][0] = parent;
    depth[u] = (parent == -1 ? 0 : depth[parent] + 1);

    for (int j = 1; j < LOG; j++)
    {
        if (up[u][j - 1] == -1)
            up[u][j] = -1;
        else
            up[u][j] = up[ up[u][j - 1] ][ j - 1 ];
    }

    for (int v : adj[u])
    {
        if (v != parent)
            dfs(v, u);
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    // bring a up to same depth as b
    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i))
            a = up[a][i];

    if (a == b)
        return a;

    // lift both until parents differ
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    adj.assign(n, {});
    up.assign(n, vector<int>(LOG, -1));
    depth.assign(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);  // root at 0

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << lca(a, b) + 1 << "\n";
    }

    return 0;
}
