// Problem Link: https://leetcode.com/problems/apply-operations-to-an-array/

//Approach-1 T.C O(N), S.C O(N) extra space in array
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
        }
       
        //counting the value of zero in nums
        int cntZero = 0; 
        for(auto val : nums){
            if(val == 0)cntZero++;
        }

        vector<int>ans; //O(N) space
        for(auto val: nums){
            if(val!=0){
                ans.push_back(val);
            }
        }

        while(cntZero){
            ans.push_back(0);
            cntZero--;
        }

        return ans;
    }
};

//Approach-2 TC = O(N) , SC = O(1) Double pass

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
        }

        int i = 0; //will help in to traverse the array
        int j = 0; //change with every non zero nums[i] and j++

        while(i<n && j<n){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
            i++;
        }

        while(j<n){
            nums[j] = 0;
            j++;
        }
        
        return nums;
    }
};

//Method 3:TC = O(N) , SC = O(1) //Single Pass
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int n = nums.size();
        
        int i = 0; //will help in to traverse the array and do the operation
        int j = 0; //change with every non zero nums[i] and j++

        while( i <n && j < n){
            if(i+1 < n && nums[i] == nums[i+1]){
                nums[i] = 2 * nums[i+1];
                nums[i+1] = 0;
            }

            if(nums[i] != 0){
                if(j != i){
                    swap(nums[i], nums[j]);
                }
                j++;
            }
            i++;
        }
        return nums;
    }
};
