class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();

        vector<int>mismatch;

        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i])mismatch.push_back(i);
        }

        if( mismatch. empty()) return true;

        if(mismatch.size() == 2){
            int idx1 = mismatch[0];
            int idx2 = mismatch[1];
            swap(s1[idx1], s1[idx2]);

            if(s1 == s2){
                return true;
            }
        }
        return false;
    }
};
