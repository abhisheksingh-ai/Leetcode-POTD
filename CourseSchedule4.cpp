class Solution {
public:
    vector<vector<int>>graph;
    vector<vector<bool>>preCompute;

    void dfs(int start, int current){
        preCompute[start][current] = true;
        for(auto neighbour: graph[current]){
            if(preCompute[start][neighbour] == false){
                dfs(start,neighbour);
            }
        }
    }

    void compute(int numCourses){
        //use dfs to check how many nodes i can go form node u
        for(int i=0;i<numCourses;i++){
            dfs(i,i);
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //make the graph
        graph.resize(numCourses);
        preCompute.assign(numCourses, vector<bool>(numCourses,false));
        //made the graph
        for(int i=0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            graph[a].push_back(b);//pushing neighbours of and b
        }

        compute(numCourses);

        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            ans.push_back(preCompute[u][v]);
        }

        return ans;
    }
};
