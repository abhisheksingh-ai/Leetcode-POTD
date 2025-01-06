class Solution {
public:
    int n; 
    vector<int>preCompute;

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        string ans = "";
        n = s.length();
        //assigning preCompute vecotr with zero
        preCompute.assign(n,0);

        //Traversing on shifts
        for(int i=0;i<shifts.size(); i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if(direction == 0){
                preCompute[start] -= 1; //from start to end,effect of  -1 will come
                if((end + 1) < n){
                    preCompute[end+1] += 1;//from end + 1 to n,effect of  -1 will vanish
                }
            }else if(direction == 1){
                preCompute[start] += 1; //from start to end,effect of  -1 will come
                if((end + 1) < n){
                    preCompute[end+1] -= 1;//from end + 1 to n,effect of  -1 will vanish
                }
            }

        }

        //do prefix sum of precompute
        for(int i=1;i<n;i++){
            preCompute[i] += preCompute[i-1];
        }

        for(int i=0;i<n;i++){
            preCompute[i] = preCompute[i] % 26;
        }

        //now check for corner cases
         for (int i = 0; i < n; i++) {
            int currChar = s[i] - 'a';  // Convert character to 0-based index (0 for 'a', 25 for 'z')
            int newChar = (currChar + preCompute[i]) % 26;  // Apply shift with wrapping
            if (newChar < 0) newChar += 26;  // Handle negative shifts (wrap around to 'z')
            ans.push_back('a' + newChar);  // Convert back to character
        }
        return ans;
    }
};