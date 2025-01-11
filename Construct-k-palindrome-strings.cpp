class Solution {
public:
    bool canConstruct(string s, int k) {
        bool ans = true;

        int length = s.length();

        if(k > length)return false;
        // no of palindrome string required is more than string characters

        vector<int>hash(26,0);
        
        for(int i=0;i<length;i++){
            char ch = s[i];
            hash[ch - 'a']++;
        }

        int oddCount = 0;

        for(int i=0;i<26;i++){
            if(hash[i]%2 == 1)oddCount++;
        }

        if(oddCount > k)return false;

        return ans;
    }
};
