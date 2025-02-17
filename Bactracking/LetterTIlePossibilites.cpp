class Solution {
public:
    int rec(int level, int len, vector<int>& freq){// how many non empty sequence of letter i can make 
    //of length == len
        //base case
        if(level >= len){
            return 1;
        }

        int ans = 0;
        //choices
        for(int i=0;i<freq.size();i++){
            if(freq[i] == 0)continue;
            //try
            freq[i]--;
            ans += rec(level+1, len, freq);
            freq[i]++;
        }
        return ans;
    }

    int numTilePossibilities(string tiles) {

        int size = tiles.length();
        int ans = 0;

        vector<int>freq(26,0);
        for(int i=0;i<size;i++){
            char ch = tiles[i];
            freq[ch - 'A']++;
        }

        for(int len = 1; len<=size; len++){
            ans += rec(0,len, freq);
        }

        return ans;
    }
};
