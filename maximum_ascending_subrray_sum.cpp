class Solution {
public:
    int n;
    int maxAns = 0;

    void LISum(vector<int>& nums){
        int head = 0;
        int tail = 0;

        while(tail<n){
            int currSum = nums[head];
            while(head+1<n && nums[head+1] > nums[head]){
                head++;
                currSum += nums[head];
            }

            maxAns = max(currSum, maxAns);

            if(tail == head){
                head++; 
                tail++;
            }else{
                tail = head + 1;
                head = tail;
            }
        }
    }

    int maxAscendingSum(vector<int>& nums) {
        n = nums.size();

        LISum(nums);

        return maxAns;
    }
};
