class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        // Sort the array
        sort(nums.begin(), nums.end());
        // Iterate through the array
        for(int i = 0; i < n - 2; i++){
            // Skip duplicates for the first number
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;  // Second Pointer
            int k = n - 1;  // Third pointer
            while(j < k){
                int current_sum = nums[i] + nums[j] + nums[k];
                if(current_sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    // Move pointers and skip duplicates
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    while(j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                } else if(current_sum > 0){
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};