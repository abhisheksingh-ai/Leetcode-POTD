class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long>mst;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int element = nums[i];
            mst.insert(element);
        }
        int operation = 0;
        while(mst.size()>1 && *mst.begin()<k){
            long long x = *mst.begin();
            mst.erase(mst.begin());
            long long y = *mst.begin();
            mst.erase(mst.begin());
            long long newElement = min(x,y)*2 + max(x,y);
            mst.insert(newElement);
            operation++;
        }
        return operation;
    }
};
