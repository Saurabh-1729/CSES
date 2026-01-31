/*
“Every node’s farthest node must be one of the two diameter endpoints.”

1. Pick any node and calculate the fartest distance from that node/
2. Now the farthest calculaed node will be the starting point of the second dfs, and that will give us the second another farthest node that is the other end of the diametere

Now we can run the BFS on the above two nodes and can calculate the distance of each node from that farthest node.
  */


ll d = -1, x = -1;

void dfs(ll v, ll parent, ll level, vector<vector<ll>> &adj)
{
    for (auto it : adj[v])
    {
        if (it != parent)
        {
            dfs(it, v, level + 1, adj);
        }
    }
    if (level > d)
    {
        d = level;
        x = v;
    }
}

void bfs(ll v, vector<ll> &dis, vector<vector<ll>> &adj)
{
    queue<ll> q;
    q.push(v);
    dis[v] = 0;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
         // Node can be revisited and can get overwritten that is parents gets revisited from the child node and causes infinite loop
            if (dis[it] == -1) // ✅ VISITED CHECK
            {
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }
}

void Saurabh()
{
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll a, b; // two fartest node
    dfs(0, -1, 0, adj);
    a = x;
    d = -1;
    x = -1;
    dfs(a, -1, 0, adj);
    b = x;
    vector<ll> disa(n, -1), disb(n, -1);
    bfs(a, disa, adj);
    bfs(b, disb, adj);
    for (int i = 0; i < n; i++)
        cout << max(disa[i], disb[i]) << " ";
    cout << endl;
}

int main()
{
    SPEED();
    START();
    ll t = 1;
    // cin >> t;
    while (t--)
        Saurabh();
    STOP();
    TIME();
}
