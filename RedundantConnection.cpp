class Solution {
public:
    vector<vector<int>>graph;
    vector<bool>visited;

    bool dfs(int u, int v){
        visited[u] = true;

        if(u == v)return true;

        for(auto neigh: graph[u]){
            if(visited[neigh] == false && dfs(neigh,v)){
                return 1;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        graph.resize(n+1);
        for(int i=0;i<n;i++){
            visited.assign(n+1,false);
            int u = edges[i][0];
            int v = edges[i][1];

            if(dfs(u,v)){
                return edges[i];
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
};
