class Solution {
public:
    string clearDigits(string s) {
        vector<int>ints;
        vector<int>chars;
        int n = s.length();

        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch >= 'a' && ch <= 'z'){
                chars.push_back(i);
            }
        }

        for(int i=n-1;i>=0;i--){
            char ch = s[i];
            if(ch >= '0' && ch <= '9'){
                ints.push_back(i);
            }
        }
        

        if(ints.size() == 0 || chars.size() == 0)return s;

        //removing left side of last digit index
        int m = chars.size()-1;
        while(!chars.empty() && chars[m] > ints[0]){
            chars.pop_back();
            m--;
        }
        
        set<int>toRemove;
        int j = 0;
        int k = chars.size()-1;

        while(j<ints.size() && k>=0){

            if(chars[k] < ints[j]){
                toRemove.insert(ints[j]);
                toRemove.insert(chars[k]);
                j++;
                k--;
            }else{
                k--;
            }
        }

        string ans="";

        for(int i=0;i<n;i++){
            if(toRemove.find(i) == toRemove.end()){
                ans += s[i];
            }
        }

        return ans;
    }
};
