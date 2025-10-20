#include <bits/stdc++.h>
using namespace std;

void __init_code()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
}

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5 + 5;
int dist[N];
int parent[N];

int main()
{
    __init_code();

    int n, e; cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--) {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    dist[0] = 0;
    parent[0] = -1; 
    for (int i = 1; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    for (int i = 1; i <= n - 1; i++) {
        for (Edge ed : EdgeList) {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;

            if (dist[u] != INT_MAX && dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                parent[v] = u; 
            }
        }
    }


    bool hasNegativeCycle = false;
    for (Edge ed : EdgeList) {
        int u = ed.u, v = ed.v, c = ed.c;
        if (dist[u] != INT_MAX && dist[u] + c < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }
    if (hasNegativeCycle) {
        cout << "Negative weight cycle detected\n";
        return 0;
    }


    cout << "Shortest distances from source (0):\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> " << dist[i] << endl;
    }



    int target;
    cin >> target;

    if (dist[target] == INT_MAX) {
        cout << "No path exists from 0 to " << target << endl;
        return 0;
    }

    vector<int> path;
    for (int cur = target; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    cout << "Shortest path from 0 to " << target << ": ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i + 1 != (int)path.size()) cout << " -> ";
    }
    cout << "\nCost: " << dist[target] << endl;

    return 0;
}
