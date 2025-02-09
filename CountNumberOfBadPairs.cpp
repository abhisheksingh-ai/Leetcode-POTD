class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;

        long long n = nums.size();

        map<int,int>mpp;

        

        for(int i=0;i<n;i++){
            int value = i - nums[i];
            mpp[value]++;
        }

        if(mpp.size()<2)return 0;

        long long b = 0;
        for(auto it = mpp.begin(); it!=mpp.end(); it++){
            if (it->second > 1) {
                //no of good pairs
                b += (1LL * it->second * (it->second - 1)) / 2;
            }
        }

        

        long long a = n * (n - 1) / 2;
        
        ans = a - b;
        return ans;
    }
};
