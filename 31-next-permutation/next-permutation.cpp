// class Solution {
// public:
//     void nextPermutation(vector<int>& nums){
//         int index = -1;
//         int n = nums.size();
//         for(int i = n-2; i >=0 ; i--){
//             if(nums[i] < nums[i+1]) {
//                 index = i;
//                 break;
//             }
//         }
//         if(index == -1){
//             reverse(nums.begin(), nums.end());
//         }else{
//             for(int i = n - 1; i > index; i--){
//                 if(nums[i] > nums[index]){
//                     swap(nums[i], nums[index]);
//                     break;
//                 }
//             }
//             reverse(nums.begin() + index + 1, nums.end());
//         }
//     }
// };

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i+1] <= nums[i]) {
            i--;
        }
        if(i >= 0) {
            int j = nums.size()-1;
            while(nums[j] <= nums[i]){
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums.begin()+i+1, nums.end());
    }

private:
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};