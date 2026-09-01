class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        vector<int> temp;

        // Merge both arrays
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i++]);
            } else {
                temp.push_back(nums2[j++]);
            }
        }
        while(i < n) temp.push_back(nums1[i++]);
        while(j < m) temp.push_back(nums2[j++]);

        int t = temp.size();
        if(t % 2 == 1){
            return temp[t/2];  // odd length
        } else {
            return (temp[t/2 - 1] + temp[t/2]) / 2.0;  // even length
        }
    }
};
