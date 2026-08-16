class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n>0){
            int set = n&1;
            n >>=1;
            if(set){
                count++;
            }
            
        }
        return count;

    }
};
