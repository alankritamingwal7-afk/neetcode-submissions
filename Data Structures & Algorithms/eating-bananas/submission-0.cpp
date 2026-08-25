//binary search on ans
class Solution {
public:
    int count_ans(vector<int>& piles, int mid){
        int total = 0;
        for(int b:piles){
            total += ceil((double)b/mid);
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = (low+high)/2;
            int count = count_ans(piles,mid);
            if(count<=h){
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
        
    }
};
