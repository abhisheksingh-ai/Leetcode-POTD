class Solution {
public:
    int n;

    int Increasing(vector<int>& nums){
        int head = 0;
        int tail = 0;
        int ans = 0;

        while(tail<n){
            while(head+1<n && nums[head+1] > nums[head]){
                head++;
            }

            ans = max(ans, head - tail + 1);

            if(head == tail){
                head++, tail++;
            }else{
                tail = head + 1;
                head = tail;
            }
        }

        return ans;
    }

    int Decreasign(vector<int>& nums){
        int head = 0;
        int tail = 0;
        int ans = 0;

        while(tail<n){
            while(head+1<n && nums[head+1] < nums[head]){
                head++;
            }

            ans = max(ans, head - tail + 1);

            if(head == tail){
                head++, tail++;
            }else{
                tail = head + 1;
                head = tail;
            }
        }

        return ans;
    }


    int longestMonotonicSubarray(vector<int>& nums) {
        n = nums.size();

        int LIS = Increasing(nums);
        int LDS = Decreasign(nums);

        int ans = max(LIS,LDS);

        return ans;
    }
};
