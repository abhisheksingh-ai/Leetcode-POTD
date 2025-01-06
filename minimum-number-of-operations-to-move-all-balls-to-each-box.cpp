class Solution {
public:
    vector<int>ones; //will store position of one in string boxes
    int n;

    void position_of_ones(string &boxes){
        for(int i=0;i<n;i++){
            char curr = boxes[i];
            if(curr == '1'){
                ones.push_back(i); // index in increasing order
            }
        }
    }

    vector<int> minOperations(string boxes) {
        n = boxes.length();
        position_of_ones(boxes);

        vector<int>result(n,0);
        for(int i=0; i<n; i++){
            //i is current index, for which we are looking the distance of ones
            int cnt = 0;
            for(int j=0;j<ones.size();j++){
                //index that constain 1 is
                int idx = ones[j];
                cnt = cnt + abs(idx - i);
            }
            result[i] = cnt;
        }
        
        return result;
    }
};