class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left,right,top,bottom,i;
        vector<int> res;
        left=0;
        right=m-1;
        top=0;
        bottom=n-1;
        while(left<=right && top<=bottom){
            //traverse the top row from left to right
            for(i=left;i<=right;i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            //traveerse thr right col from top to bottom
            for(i=top;i<=bottom;i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            //travesre bottom row from right to left
            if(top<=bottom){
                for(i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            } 
            // traverse  left col from bottom to top
            if(left<=right){
                for(i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            } 
        }
        return res;
        
    }
};
