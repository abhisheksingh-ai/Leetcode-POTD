class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int>prfxSum(n+1);

        prfxSum[0] = 0;
        for(int i=0;i<n;i++){
            prfxSum[i+1] = arr[i] + prfxSum[i];
        }

        vector<int>evenSum(n+1,0);
        vector<int>oddSum(n+1,0);

        int odd = 0;
        int even = 0;
        for(int i=0;i<n+1;i++){
            int sum = prfxSum[i];
            if(sum%2 == 0){
                //even
                even++;
            }else{
                odd++;
            }
            evenSum[i] = even;
            oddSum[i] = odd;
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            int sum = prfxSum[i];

            if(sum % 2 == 0){
                //sum is even then count previous oddSum
                ans = (ans + oddSum[i]) % mod;
            }else{
                ans = (ans + evenSum[i]) % mod;
            }
        }
        return ans;
    }
};
