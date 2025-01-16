class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        //everythng depending on size of num2
        int m = nums2.size();
        int x = 0;
        if(m&1){
            for(int i=0;i<nums1.size();i++){
                x = x ^ nums1[i];
            }
        }
        int n = nums1.size();
        int y = 0;
        if(n&1){
            for(int i=0;i<nums2.size();i++){
                y = y^nums2[i];
            }
        }

        return x^y;
    }
};
