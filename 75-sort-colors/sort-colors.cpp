class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                zeros++;
            }else if(nums[i] == 1) {
                ones++;
            }else 
                twos++;
        }
        for(int i = 0; i < zeros; i++){
            nums[i] = 0;
        }
        for(int i = zeros; i < zeros + ones; i++){
            nums[i] = 1;
        }
        for(int i = zeros + ones; i < nums.size(); i++){
            nums[i] = 2;
        }
    }
};