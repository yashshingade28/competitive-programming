template <typename Weight, typename Distance>
void dijkstra(int s, const std::vector<std::vector<std::pair<int, Weight>>> &adj, std::vector<Distance> &d, std::vector<int> &p)
{
    int n = adj.size();
    d.assign(n, std::numeric_limits<Distance>::max());
    p.assign(n, -1);

    d[s] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    q.push({0, s});

    while (!q.empty())
    {
        auto [u, d_u] = q.top();
        q.pop();

        if (d_u != d[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                p[v] = u;
                q.push({d[v], v});
            }
        }
    }
}
