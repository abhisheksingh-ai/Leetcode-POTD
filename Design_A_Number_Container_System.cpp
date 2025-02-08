class NumberContainers {
public:
    NumberContainers() {
        
    }
    map<int, set<int>>mpp;
    map<int, int>mpp2;
    void change(int index, int number) {
        if(mpp2.find(index) != mpp2.end()){
            //key mil gyi to remove from mpp also
            int num = mpp2[index];
            mpp[num].erase(index);

            if(mpp[num].empty()){
                mpp.erase(num);
            }

        }
        mpp[number].insert(index);
        mpp2[index] = number;
    }
    
    int find(int number) {

        if(mpp.find(number) == mpp.end()){
            return -1;
        }else{
            return *mpp[number].begin();
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
