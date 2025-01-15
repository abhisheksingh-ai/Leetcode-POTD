class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int result = 0;

        int setCount = __builtin_popcount(num2);

        //Making 1 from MSB
        for(int i = 31; i >= 0 && setCount > 0 ; i--){
            if(num1 & (1<<i)){
                result = result | (1<<i);
                setCount--;
            }
        }

        //if we have still left setCount
        for(int i=0; i < 32 && setCount > 0; i++){
            if((num1 & (1<<i)) == 0){
                result = result | (1<<i);
                setCount--;
            }
        }
        return result;
    }
};
