//https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

//Method-1 Recurssive 
class Solution {
  public:
    int n,m;
    // Function to find length of shortest common supersequence of two strings.
    int rec(int i,int j, string &s1, string &s2){
        
        if(i>=n){
            return m - j;
        }
        
        if(j >= m){
            return n - i;
        }
        
        //choices
        if(s1[i] == s2[j]){
            return 1 + rec(i+1,j+1,s1,s2);
        }else{
            return  min(1 + rec(i,j+1,s1,s2) ,1 + rec(i+1,j,s1,s2));
        }
    }
    
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        n = s1.length();
        m = s2.length();
        
        int ans = rec(0,0,s1,s2);
        
        return ans;
    }
};

//Method:-> 2 Memoization + recurssion
class Solution {
  public:
    int n,m;
    int dp[505][505];
    // Function to find length of shortest common supersequence of two strings.
    int rec(int n,int m, string &s1, string &s2){
        
        if(m == 0 || n == 0){
            //agr koi bhi len 0 hui to dusri wali ki send karo
            return m + n;
        }
        if(dp[n][m] != -1)return dp[n][m];
        
        //choices
        if(s1[n-1] == s2[m-1]){
            return dp[n][m] = 1 + rec(n-1,m-1,s1,s2);
        }else{
            return  dp[n][m] = min(1 + rec(n,m-1,s1,s2) ,1 + rec(n-1,m,s1,s2));
        }
        return dp[n][m] = 0;
    }
    
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        n = s1.length();
        m = s2.length();
        memset(dp,-1,sizeof(dp));
        int ans = rec(n,m,s1,s2);
        
        return ans;
    }
};
