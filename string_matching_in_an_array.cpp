class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        vector<string>result;
        
        int n = words.size();
        
        for(int i = 0;i<n ;i++){

            string isThisSubstr = words[i];

            for(int j = 0; j< n ; j++){

                if (i == j)continue;

                string temp = words[j];

                auto position = temp.find(isThisSubstr);

                if(position != string::npos){

                    result.push_back(isThisSubstr);
                    
                    break;
                }
            }
        }
        return result;
    }
};