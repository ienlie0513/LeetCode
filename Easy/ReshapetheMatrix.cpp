class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(r*c != m*n)
            return mat;
        
        vector<vector<int>> ans(r, vector<int>(c,0));
        for(int k=0; k<m*n; k++){
            ans[k/c][k%c] = mat[k/n][k%n];
        }
        
        return ans;
    }
};
