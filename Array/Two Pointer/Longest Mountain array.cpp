// https://leetcode.com/problems/longest-mountain-in-array/?envType=problem-list-v2&envId=9ns2k47r
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int s = 0;
        int n = arr.size();
        int maxLen = 0;
        while(s <= n-3){
            int i = s;
            while(i+1<n && arr[i+1]>arr[i]){
                i++;
            }
            if(s == i){
                //s == i -> if peak is same as start mean no increasing part
                s++;
                continue;
            }

            int e = i;

            while(e + 1 < n && arr[e] > arr[e+1]){
                e++;
            }

            int len = e - s + 1;

            if(e > i){
                //valid peak
                maxLen = max(maxLen , len);
            }

            s = e;
        }
        return maxLen;
    }
    
};
