/*
for krushkal algorithm

we first sort the edges based on their weights.
Then we pick the smallest edge. If it forms a cycle with the spanning tree formed so far, we discard it. Otherwise, we include it in the spanning tree.
We repeat this process until we have included enough edges (V-1 edges for a graph with V vertices).
*/


class DSU {
    vector<int>parent,rank;

    public :
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
}




int minimumSpanningTree(vector<vector<int>>&graph){

    int n = graph.size();
    vector<pair<int, pair<int, int>>> edges;

    // Step 1: Create a list of all edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({graph[i][j], {i, j}});
            }
        }
    }


    // Step 2: Sort edges based on weight
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int mstWeight = 0;

    // Step 3: Iterate through edges and apply union-find
    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            mstWeight += weight;
        }
    }

    return mstWeight;
}