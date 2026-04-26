// class Solution {
// public:
// vector<vector<int>> threeSum(vector<int>& nums) {
//     set<vector<int>> st;
//     for(int i = 0; i < nums.size(); i++) {
//         set<int> hashSet;
//         for(int j = i+1; j < nums.size(); j++) {
//             int third = -(nums[i] + nums[j]);
//             if(hashSet.find(third) != hashSet.end()) {      
//                 vector<int> temp = {nums[i], nums[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashSet.insert(nums[j]);
//         }
//     }
//     vector<vector<int>> res(st.begin(), st.end());
//     return res;
// }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    j++;
                }else if(sum > 0) {
                    k--;
                }else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};