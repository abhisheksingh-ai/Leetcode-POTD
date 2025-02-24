class Solution {
public:
    vector<vector<int>> g; // graph
    vector<int> parent;    // parent of each node
    vector<bool> visitedParent;
    vector<int> bobTime;   // time Bob reaches each node
    vector<bool> isLeaf;   // whether a node is a leaf
    vector<bool> visitedLeaf;
    vector<bool> visited;  // for Alice's DFS
    int ans = INT_MIN;

    void makeGraph(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // number of nodes is edges + 1 in a tree
        g.resize(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
    }

    void dfsParent(int node, int par) {
        visitedParent[node] = true;
        parent[node] = par;
        for (auto v : g[node]) {
            if (!visitedParent[v]) {
                dfsParent(v, node);
            }
        }
    }

    void preComputeBobTime(int node) {
        int time = 0;
        bobTime[node] = time;
        while (parent[node] != -1) { // Stop at root (parent = -1)
            node = parent[node];
            time++;
            bobTime[node] = time;
        }
    }

    void LeafNodeCheck(int node) {
        visitedLeaf[node] = true;
        if (g[node].size() > 1 || (node == 0 && g[node].size() > 0)) {
            isLeaf[node] = false; // Not a leaf if it has >1 neighbor (or root with children)
        }
        for (auto v : g[node]) {
            if (!visitedLeaf[v]) {
                LeafNodeCheck(v);
            }
        }
    }

    void rec(int a, int money, int time, vector<int>& amount) {
        // Calculate cost based on Bob's presence
        int cost = amount[a];
        if (bobTime[a] != -1 && time > bobTime[a]) {
            cost = 0; // Bob already took it
        } else if (bobTime[a] != -1 && time == bobTime[a]) {
            cost = amount[a] / 2; // Split with Bob
        }

        // Base case: leaf node
        if (isLeaf[a]) {
            ans = max(ans, money + cost);
            return;
        }

        // Mark current node visited
        visited[a] = true;
        for (auto v : g[a]) {
            if (!visited[v]) {
                rec(v, money + cost, time + 1, amount);
            }
        }
        visited[a] = false; // Backtrack
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        
        // Initialize all vectors
        makeGraph(edges);
        parent.assign(n, -1);
        visitedParent.assign(n, false);
        bobTime.assign(n, -1);
        isLeaf.assign(n, true);
        visitedLeaf.assign(n, false);
        visited.assign(n, false);

        // Compute parents
        dfsParent(0, -1); // Root has parent -1

        // Precompute Bob's path times
        preComputeBobTime(bob);

        // Identify leaf nodes
        LeafNodeCheck(0);

        // Run Alice's DFS
        rec(0, 0, 0, amount);

        return ans;
    }
};
