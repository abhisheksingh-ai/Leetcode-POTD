class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i=0;i<n;i++){

            string str1 = words[i];
            int len1 = str1.length();

            for(int j=0; j<n; j++){

                if(i>=j)continue;
                string str2 = words[j];
                int len2 = str2.length();
                if(len1 > len2)continue;

                string prefix = str2.substr(0,(len1 >= len2) ? len2 : len1);
                string suffix = str2.substr(((len2 - len1)>= 0 ? len2-len1 : len1));
                if((prefix == str1) && (suffix == str1)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};