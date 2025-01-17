class Solution {
public:
    bool checkValid(vector<int>& original, int n, vector<int>& derived){
        for(int i=n-2; i>=1; i--){
            if(derived[i] == 1){
                if(original[i+1] == 0){
                    original[i] = 1;
                }
                if(original[i+1] == 1){
                    original[i] = 0;
                }
            }else{
                //derived[i] == 0
                original[i] = original[i+1];
            }
        }
        //check in the do you have made the correct orinial array by checking last thing
        if(derived[0] == (original[0] ^ original[1]))return true;
        return false;
    }

    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n==1){
            int element = derived[0];

            if(element == 0){
                return true;
            }else{
                return false;
            }
        }
        vector<int> original_1(n,-1);
        vector<int> original_2(n,-1);

        //1. checking the last elment of derived that We have to make
        int lastElement = derived[n-1];
        //it would have been come from xoring of first element and last element of orginal
        //We dont have the value of original[0]

        //2. lets assume based on last element
        if(lastElement){
            //if last element is 1 than orginal's 0th and n-1th will be opposite according to xor property
            original_1[0] = 1;
            original_1[n-1] = 0;

            original_2[0] = 0;
            original_2[n-1] = 1;
        }else{
            original_1[0] = 1;
            original_1[n-1] = 1;

            original_2[0] = 0;
            original_2[n-1] = 0;
        }
        bool ans1 = checkValid(original_1, n, derived);
        bool ans2 = checkValid(original_2, n, derived);

        return ans1 | ans2;
    }
};
