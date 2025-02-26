class Solution {
public:
    
    int kadane (vector<int>& nums){//return the maxsum
        int maxSum = -1e9;
        int currSum = 0;

        for(auto num: nums){
            currSum = currSum + num;
            if(currSum < 0){
                currSum = 0;
            }
            maxSum = max(currSum , maxSum);
        }
        return maxSum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = kadane(nums);

        for(auto &num : nums) num = -num;

        int minSum = kadane(nums);

        return max(maxSum,minSum );
    }
};
