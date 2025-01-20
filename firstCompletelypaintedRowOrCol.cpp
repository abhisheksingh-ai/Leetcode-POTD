class Solution {
public:
    vector<pair<int,int>>location;

    void preComputeTheLocations(vector<vector<int>>& mat){
        for(int i=0; i<mat.size(); i++){
            for(int j=0;j<mat[0].size();j++){
                location[mat[i][j]] = {i,j};
            }
        }
    }

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int N = arr.size();
        location.resize(m * n + 1);
        preComputeTheLocations(mat);

        vector<int>rows(m,n);
        vector<int>cols(n,m);

        for(int i=0;i<N;i++){
            int value = arr[i];
            //Look where this value exist in matrix
            int r = location[value].first;
            int c = location[value].second;

            rows[r]--;
            cols[c]--;

            if(rows[r] <= 0 || cols[c] <= 0){
                return i;
            }
        }
        return 0;
    }
};
