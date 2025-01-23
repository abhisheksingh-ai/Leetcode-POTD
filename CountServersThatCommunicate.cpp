class Solution {
    class UnionFind
     {
                 public:
          vector<int> ranks;
          vector<int> parents;
 
          UnionFind(vector<vector<int>>& grid)
          {
                 int m = grid.size();
                 int n = grid[0].size();
 for(int i = 0;i < m; i++) 
       {
           for(int j  = 0;j < n; j++)
          {
                if(grid[i][j] == 1)
                       parents.push_back(i *n +j);
              else
                      parents.push_back(-1);
              ranks.push_back(1);
             }
        }
          }
          
          int FindParents(int a)
          {
                 if(a != parents[a])
                  parents[a] = FindParents(parents[a]);


               return parents[a]; 
           }

          void FindUnion(int a, int b)
          {

                int parent_a = FindParents(a);
                int parent_b = FindParents(b);
                
               if(parent_a == parent_b)
                  return;

              if(ranks[parent_a] >= ranks[parent_b])
              {
                   ranks[parent_a] += ranks[parent_b];
                   parents[parent_b] = parent_a;
              }
              else
              {
                  ranks[parent_b] += ranks[parent_a];
                   parents[parent_a] = parent_b;
               }
         }
     };

public:
    int countServers(vector<vector<int>>& grid) {
         UnionFind ufs(grid);
         int count_servers  = 0;
         int m = grid.size();
         int n = grid[0].size();
         queue<pair<int,int>> qq;
         for(int i  = 0;i < m; i++)
         {
               for(int j = 0;j < n ;j++)
               {
                    if(grid[i][j] == 1)
                         qq.push({i, j});
               }
         }
         
         while(!qq.empty())
         {
 
             pair<int,int> front = qq.front();
             int x = front.first;
             int y = front.second;
             qq.pop();
            for(int j = 0; j < n; j++)
            { 
                if(j != y && grid[x][j] == 1)
                  ufs.FindUnion(x*n +y, x*n +j);
                
            }

            for(int i = 0;i < m; i++)
            {
                if(i != x && grid[i][y] == 1)
                    ufs.FindUnion(x*n +y, i*n +y);
                
            }

         }
          
              set<int> st;
                 for(int i = 0;i < m; i++)
             {
                 for(int j  =0;j < n; j++)
                {
                       if(ufs.ranks[i*n+j] > 1)
                       {
                         int parent = ufs.FindParents(i*n+j);
                         if(!st.contains(parent))
                         {
                           st.insert(parent);
                           count_servers += ufs.ranks[parent];
                         }
                       }
                 } 
              }

            return count_servers;   
    }
};
