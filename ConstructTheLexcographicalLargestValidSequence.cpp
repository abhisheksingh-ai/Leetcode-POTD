class Solution {
public:
    vector<int> ans;
    int size;
    vector<int>used; // Max heap to prioritize larger numbers

    bool rec(int index, int n) {//can i put max number at this index
        //base case
        if(index >= size){ // i already filled everything correctly
            return true;
        }

        if(ans[index]!=0){ //if this is already filled then move to next index
            return rec(index+1,n);
        }
        //choices
        for(int num = n; num >= 1; num--){
            if(used[num] == true)continue; //num is used
            
            //try this number
            used[num] = true;
            ans[index] = num;
            //explore
            if(num == 1){// if number was 1, after putting if i explore
                if(rec(index+1,n) == true){
                    return true;
                }
            }else{
                //num is not 1
                int j = ans[index] + index;

                if(j<size && ans[j]==0){
                    //try
                    ans[j] = num;
                    //explore
                    if(rec(index+1,n) == true){
                        return true;
                    }
                    //undo
                    ans[j] = 0;
                }
            }
            used[num] = false;
            ans[index] = 0;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        size = 2 * n - 1;
        ans.assign(size, 0);
        used.assign(n+1,false);
        rec(0,n);
        return ans;
    }
};
