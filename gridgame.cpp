class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long  firstRowRem = 0;

        for(int i=0;i<n;i++){
            firstRowRem+= grid[0][i];
        }

        long long secondRowRem = 0;
        long long ans = LONG_LONG_MAX;
        for(int c=0;c<n;c++){
            firstRowRem = firstRowRem - grid[0][c];
            long long bestOfRobot2 = max(firstRowRem,secondRowRem);
            ans = min(bestOfRobot2, ans);

            secondRowRem+= grid[1][c];
        }
        return ans;

    }
};
