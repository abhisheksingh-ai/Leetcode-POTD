class Solution {
public:
    bool check(long long x, vector<int>& ranks, int cars){
        long long carCount = 0;
        for(auto r : ranks){
            carCount += (long long) sqrt(x / r);
        }
        return carCount >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1e15+1;
        long long ans = high;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(check(mid, ranks, cars)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
