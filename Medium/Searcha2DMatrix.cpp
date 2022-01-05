class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i;
        
        for(i=0; i<m; i++){
            if(matrix[i][n-1] >= target){
                break;
            }
        }
        if(i != m){
            return binary_search(matrix[i].begin(), matrix[i].end(), target);
        }
        return false;
    }
};
