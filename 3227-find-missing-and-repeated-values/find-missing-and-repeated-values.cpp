class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n*n;
        vector<int> freq(total + 1, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                freq[grid[i][j]]++;
            }
        }
        int repeated = -1;
        int missing = -1;
        for(int num = 1; num <= total; num++){
            if(freq[num] == 2) {
                repeated = num;
            }else if(freq[num] == 0) {
                missing = num;
            }
        }
        return {repeated, missing};
    }
};