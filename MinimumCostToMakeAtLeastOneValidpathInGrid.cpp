class Solution {
public:
    vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int cost) {
        if(i == m-1 && j == n-1) { //reached destination
            return cost;
        }

        visited[i][j] = true;

        //explore
        int minCost = INT_MAX;
        for(int dir_i = 0; dir_i <= 3; dir_i++) {
            int i_ = i + dir[dir_i][0];
            int j_ = j + dir[dir_i][1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                int nextCost = cost + ((grid[i][j]-1 != dir_i) ? 1 : 0);
                
                minCost = min(minCost, dfs(i_, j_, grid, visited, nextCost));
            }
        }

        visited[i][j] = false;
        return minCost;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfs(0, 0, grid, visited, 0);//explore all paths by backtracking
    }
};
