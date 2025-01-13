class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();

        vector<int>hash(26,0);

        for(int i=0;i<n;i++){
            char ch = s[i];
            hash[ch-'a']++;
        }

        int len = 0;

        for(int i=0;i<26;i++){
            int freq = hash[i];

            if(freq&1){
                len = len + 1;
            }else{
                if(freq!=0){
                    len = len + 2;
                }
            }
        }
        return len;
    }
};
