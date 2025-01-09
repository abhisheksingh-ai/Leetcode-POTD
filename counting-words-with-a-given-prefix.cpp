class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        int len1 = pref.length();
        for(int i=0;i<words.size();i++){
            string curr = words[i];
            int len2 = curr.length();
            if(len2<len1) continue;
            string prefixString = curr.substr(0,len1);
            if(prefixString == pref)cnt++;
        }
        return cnt;
    }
};
