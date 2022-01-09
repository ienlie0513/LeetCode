class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> row;
    
        for(int i=0; i<numRows; i++){
            row.push_back(1);
            for(int j=1; j<i; j++)
                row.push_back(ans[i-1][j-1] + ans[i-1][j]);
            if(i)
                row.push_back(1);
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};