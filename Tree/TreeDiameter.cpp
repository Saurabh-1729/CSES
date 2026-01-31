long long diameter = 0;

int dfs(int v, int parent, vector<vector<int>> &adj)
{
    int best1 = 0, best2 = 0;

    for (int u : adj[v])
    {
        if (u == parent) continue;

        int height = dfs(u, v, adj);

        if (height > best1)
        {
            best2 = best1;
            best1 = height;
        }
        else if (height > best2)
        {
            best2 = height;
        }
    }

    diameter = max(diameter, best1 + best2);
    return best1 + 1;
}
