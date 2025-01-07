#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e3 + 10;
int parent[N], sz[N];

void make(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find(int v) {
    if (v == parent[v]) return v;
    // Path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        // Union by sz
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    int n, i, j; cin >> n;

    vector<pair<int, int>> cities(n + 1);
    for (i = 1; i <= n; i++) {
        cin >> cities[i].first >> cities[i].second;

    }

    vector<int> c(n + 1), k(n + 1);

    for (i = 1; i <= n; i++) cin >> c[i];
    for (i = 1; i <= n; i++) cin >> k[i];

    vector<pair<ll, pair<int, int>>> edges;

    for (i = 1; i <= n; i++) {
        edges.push_back({c[i], {0, i}});
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            int dist = abs(cities[i].first - cities[j].first)  + abs(cities[i].second - cities[j].second);

            ll cost = dist * 1ll * (k[i] + k[j]);

            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) make(i);

    ll total_cost = 0;
    vector<int> power_stations;
    vector<pair<int, int>> connections;
    for (auto &edge : edges) {
        ll wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(u) == find(v)) continue;

        Union(u, v);
        total_cost += wt;

        if (u == 0 || v == 0) {
            power_stations.push_back(max(u, v));
        } else {
            connections.push_back({u, v});
        }
    }
    cout << total_cost << '\n';
    cout << power_stations.size() << '\n';
    for (auto &station : power_stations) {
        cout << station << ' ';
    }
    cout << '\n';

    cout << connections.size() <<'\n';
    for (auto &connection : connections) {
        cout << connection.first <<' ' <<connection.second << '\n';
    }

    return 0;
}
