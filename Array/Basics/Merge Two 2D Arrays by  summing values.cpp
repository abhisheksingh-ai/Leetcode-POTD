// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/

//Approach:1 Map to store key , Drawback- using extra space in the map
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mpp;

        int n = nums1.size();
        int m = nums2.size();

        for(int i=0;i<n;i++){
            mpp[nums1[i][0]] = nums1[i][1];
        }

        for(int i=0;i<m;i++){
            vector<int>temp = nums2[i];
            //temp [id, val]
            int id = temp[0];
            int val = temp[1];

            if(mpp.count(id)){
                mpp[id] = mpp[id] + val;
            }else{
                mpp[id] = val;
            }
        }

        vector<vector<int>>ans;

        for(auto it = mpp.begin(); it!=mpp.end(); it++){
            vector<int>temp;
            temp.push_back(it->first);
            temp.push_back(it->second);
            ans.push_back(temp);
        }

        return ans;
    }
};

//Approach-2 Without using map ( Two Pointer) 
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0; //use to traverse on the nums1
        int j = 0; // use to traverse on the nums2

        vector<vector<int>>ans;

        while(i<n && j<m){
            //value and id form nums1
            int id1 = nums1[i][0];
            int val1 = nums1[i][1];

            //value and id from nums2
            int id2 = nums2[j][0];
            int val2 = nums2[j][1];

            if(id1 == id2){
                int val = val1 + val2;
                ans.push_back({id1,val});
                i++;
                j++;
            }else if(id1 > id2){
                ans.push_back({id2,val2});
                j++;
            }else{
                ans.push_back({id1,val1});
                i++;
            }
        }

        while(i<n){
            ans.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }

        while(j<m){
            ans.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
        return ans;
    }
};
