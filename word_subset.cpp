class Solution {
public:
    vector<int>freq_2;

    void mapping(vector<string>& words2) {
        for (string temp : words2) {
            vector<int> tempFreq(26, 0);
            for (char ch : temp) {
                tempFreq[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                freq_2[i] = max(freq_2[i], tempFreq[i]);
            }
        }
    }


    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        freq_2.assign(26,0);
        mapping(words2);
        
        vector<string>result;

        for(int i=0;i<words1.size();i++){

            string temp = words1[i];

            vector<int>freq_1(26,0);

            for(int i=0; i<temp.size();i++){
                char ch = temp[i];
                freq_1[ch - 'a']++;
            }
            
            //print(freq_1);

            bool isUniversal = true;

            for(int i=0 ; i<26; i++){
                if(freq_1[i]<freq_2[i]){
                    isUniversal = false;
                    break;
                }
            }

            if(isUniversal){
                result.push_back(temp);
            }
        }
        return result;
    }
};
