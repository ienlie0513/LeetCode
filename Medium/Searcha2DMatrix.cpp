class Solution {
private:
    bool binarySearch(vector<vector<int>>& matrix, int start, int end, int target){
        if(start == end)
            return false;
        
        int n = matrix[0].size();
        int cur = int((start+end))/2;
        int r = cur/n;
        int c = cur%n;
        
        if(matrix[r][c] == target)
            return true;
        
        if(end-start == 1)
            return false;
        
        if(matrix[r][c] > target)
            return binarySearch(matrix, start, cur, target);
        else
            return binarySearch(matrix, cur, end, target);
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return this->binarySearch(matrix, 0, matrix.size()*matrix[0].size(), target);
    }
};
