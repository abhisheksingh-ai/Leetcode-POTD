class CustomDS {
public:
    map<int,int>mpp;
    int count = 0;
    void insert(int x){
        mpp[x]++;
        if(mpp[x]>1){
            count++;
        }
    }
    int getCount(){
        return count;
    }
};

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>C(n);
        CustomDS DS;
        for(int i=0;i<n;i++){
            DS.insert(A[i]);
            DS.insert(B[i]);
            int value = DS.getCount();
            C[i] = value;
        }
        return C;
    }
};
