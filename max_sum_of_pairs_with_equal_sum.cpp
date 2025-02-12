class Solution {
public:
    int n;
    //task:2
    int findDigitSum(int x){
        int sum = 0;
        while(x){
            sum += x % 10;
            x = x / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        n = nums.size();
        vector<int>digitSum;
        //task:1
        for(int i=0;i<n;i++){
            int sum = findDigitSum(nums[i]);
            digitSum.push_back(sum);
        }
        //task: 3
        map<int, priority_queue<int>>mpp;
        for(int i=0;i<n;i++){
            int sumOfDigit = digitSum[i];
            mpp[sumOfDigit].push(nums[i]);
        }
        int maxSum = -1;
        for(auto it = mpp.begin(); it!= mpp.end(); it++){
            priority_queue<int>pq = it->second;
            if(pq.size()>=2){
                int x = pq.top();
                pq.pop();
                int y = pq.top();
                int currentSum = x + y;
                maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
};
