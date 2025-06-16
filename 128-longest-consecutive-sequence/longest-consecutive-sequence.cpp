class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int count = 1;
        int temp = 1 ;
        
        for(int i = 0; i < nums.size()-1; i++) {
            if((nums[i] == nums[i+1]) || (nums[i] == (nums[i+1] - 1) )) {
                if((nums[i] == (nums[i+1] - 1))){
                    temp++; 
                }            
            }else {
                count = max(temp, count);
                temp = 1;
            }
            count = max(temp, count);
        }
        return count;
    }
};