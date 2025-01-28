class Solution {
public:
    int n;
    int m;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};

    int rec(int r, int c, vector<vector<int>>& grid){
        //base case
        if(r >= m || c >= n || r < 0 || c < 0 || grid[r][c] == 0)return 0;
        //choices
        int ans = grid[r][c];
        grid[r][c] = 0;
        //make it visited or block now i dont want to come here again
        for(int k = 0; k<4 ; k++){
            int nr = r + dx[k];
            int nc = c + dy[k];
            //check is this choice even valid
            // if(nr < m && nc < n && grid[nr][nc] != 0){
            //     ans = ans + rec(nr,nc,grid);
            // }
            ans += rec(nr,nc,grid);
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        if(m == 0)return 0;
        n = grid[0].size();
        if(n == 0)return 0;

        int ans = 0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c] != 0){
                    ans = max(ans, rec(r,c,grid));
                }
            }
        }
        return ans;
    }
};
