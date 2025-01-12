class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n&1)return false;
        bool ans = true;
        //1. Cheking unbalance due to closing bracked parsing from L --> R
        int closing = 0;
        int opening = 0;
        int wildCard = 0;
        for(int i=0;i<n;i++){
            if(locked[i] == '0'){
                wildCard++;
            }else{
                if(s[i] == '('){
                    opening++;
                }else{
                    closing++;
                }
            }
            //check condition
            if((wildCard + opening) < closing){
                return false;
            }
        }

        //2. Cheking unbalance due to opening bracked parsing from R --> L
        closing = 0;
        opening = 0;
        wildCard = 0;
        for(int i=n-1;i>=0;i--){
            if(locked[i] == '0'){
                wildCard++;
            }else{
                if(s[i] == '('){
                    opening++;
                }else{
                    closing++;
                }
            }
            //check condition
            if((wildCard + closing) < opening){
                return false;
            }
        }
        return ans;
    }
};
