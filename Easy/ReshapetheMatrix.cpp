class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(r*c != m*n)
            return mat;
        
        vector<vector<int>> ans(r, vector<int>(c,0));
        int d1=0, d2=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[d1][d2++] = mat[i][j];
                if(d2>=c){
                    d1++;
                    d2 = 0;
                }
            }
        }
        return ans;
    }
};
