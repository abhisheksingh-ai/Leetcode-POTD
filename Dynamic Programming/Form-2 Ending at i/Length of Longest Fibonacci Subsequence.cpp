// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/

//method:1 Recurssion 
//generation all subseq
//Time Complexity: O(N^3)

class Solution {
public:
    int n;

    int solve(int j, int k, vector<int>& arr, map<int,int>& mpp){
        int a = arr[k] - arr[j];

        if(mpp.count(a) && mpp[a] < j){
            return solve(mpp[a], j, arr, mpp)+1;
        }

        return 2;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        n = arr.size();
        int result = 0;

        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]] = i;
        }

        for(int j = 1;j<n;j++){
            for(int k = j+1;k<n;k++){
                int len = solve(j,k,arr,mpp);

                if(len>=3){
                    result = max(result,len);
                }
            }
        }

        return result;
    }
};

//Method:2 Using Dynamic Programming

class Solution {
public:
    int n;
    int dp[1001][1001];

    int solve(int j, int k, vector<int>& arr, map<int,int>& mpp){

        if(dp[j][k] != -1)return dp[j][k];

        int a = arr[k] - arr[j];

        
        if(mpp.count(a) && mpp[a] < j){
            int ans =  solve(mpp[a], j, arr, mpp)+1;
            dp[j][k] =  ans;
            return ans;
        }

        

        return dp[j][k] = 2;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        n = arr.size();
        int result = 0;
        memset(dp,-1,sizeof(dp));
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]] = i;
        }

        for(int j = 1;j<n;j++){
            for(int k = j+1;k<n;k++){
                int len = solve(j,k,arr,mpp);

                if(len>=3){
                    result = max(result,len);
                }
            }
        }

        return result;
    }
};

//method 3: Bottom Up
class Solution {
public:
    int n;
    vector<vector<int>>dp;

    // int solve(int j, int k, vector<int>& arr, map<int,int>& mpp){

    //     if(dp[j][k] != -1)return dp[j][k];

    //     int a = arr[k] - arr[j];

        
    //     if(mpp.count(a) && mpp[a] < j){
    //         int ans =  solve(mpp[a], j, arr, mpp)+1;
    //         dp[j][k] =  ans;
    //         return ans;
    //     }

        

    //     return dp[j][k] = 2;
    // }

    int lenLongestFibSubseq(vector<int>& arr) {
        n = arr.size();
        int result = 0;
        dp.assign(1001, vector<int>(1001, 2));
        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < dp.size(); j++){
                dp[i][j] = 2;
            }
        }
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]] = i;
        }

        for(int j = 1;j<n;j++){
            for(int k = j+1;k<n;k++){
                int target = arr[k] - arr[j];
                if(mpp.count(target) && mpp[target] < j){
                    int i = mpp[target];
                    dp[j][k] = dp[i][j] + 1;
                }
                result = max(result, dp[j][k]);
            }
        }

        return result >= 3 ? result : 0;
    }
};
