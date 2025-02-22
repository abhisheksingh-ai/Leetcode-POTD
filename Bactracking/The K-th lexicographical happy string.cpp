class Solution {
public:
    
    void rec(string &s, int n, int &k, int level, string &ans){
        if(k == 1 && level == n){
            ans = s;
            return;
        }
        //base case
        if(level == n){
            // i got one happy string 
            k--;
            return;
        }
        //choices
        // at level 0 we have three choices
        for(char ch = 'a'; ch <= 'c'; ch++){
            //is this valid choice?? 
            //check from previous choice --> skip previous choice
            if(level > 0 && ch == s[level - 1]) continue;// dont check from back just push
            s.push_back(ch);
            //is recurssion se mera base case k according answer aa jayga
            rec(s,n,k,level+1,ans);
            s.pop_back();
            //dont check more choice now 
            if (!ans.empty()) return;
        }
        return;
    }

    string getHappyString(int n, int k) {
        string s = "";
        string ans;
        rec(s,n,k,0,ans); // I will move from a->b->c so that i got the lexicographical order 
        return ans;
    }
};
