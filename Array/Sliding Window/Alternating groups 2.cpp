class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        deque<int>dq;
        int ans = 0;
        for(int curr = 0; curr < n+k-1; curr++){
            //addition in deque
            int color = colors[curr % n];
            if(dq.empty() || dq.back() != color){
                dq.push_back(color);
            }else if(dq.back() == color){
                dq.clear();
                dq.push_back(color);
            }
             //getting answer from this curr
            if(curr - k + 1 >=0){
                if(dq.size() >= k){
                    ans++;
                }
            }
            //removing element
            if(curr - k >= 0){
                if(dq.size() >= k){
                    dq.pop_front();
                }
            }
        }
        return ans;
    }
};
