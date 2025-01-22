class Solution {
public:

    using state = pair<int,int>

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>height;
        //height is distance array here and doing multisource bfs
        height.assign(m, vector<int>(n,-1));
        //height array is also help to track the visited cells

        //Queue data structure for BFS
        queue<state>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 0){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            state curr = q.front();
            q.pop();
            
            int x = curr.first;
            int y = curr.second;
            //adding its neighbour if its not visited and making height 1

            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && nx<m && ny>=0 && ny<n && height[nx][ny] == -1){
                    height[nx][ny] = height[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        return height;
    }
};
