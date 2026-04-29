class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        int xr = 0;

        // XOR all grid values
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                xr ^= grid[i][j];
            }
        }

        // XOR numbers from 1 to n*n
        for (int i = 1; i <= N; i++) {
            xr ^= i;
        }

        // xr = repeated ^ missing
        int bit = xr & -xr;   // rightmost set bit

        int zero = 0, one = 0;

        // Divide grid values into two groups
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] & bit) {
                    one ^= grid[i][j];
                } else {
                    zero ^= grid[i][j];
                }
            }
        }

        // Divide numbers 1 to n*n into two groups
        for (int i = 1; i <= N; i++) {
            if (i & bit) {
                one ^= i;
            } else {
                zero ^= i;
            }
        }

        // Find which one is repeated
        int countZero = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == zero) {
                    countZero++;
                }
            }
        }

        if (countZero == 2) {
            return {zero, one}; // {repeated, missing}
        }

        return {one, zero};
    }
};