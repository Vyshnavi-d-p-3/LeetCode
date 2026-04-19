class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positiveElements;
        vector<int> negativeElements;
        vector<int> res(n);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0){
                positiveElements.push_back(nums[i]);
            }else {
                negativeElements.push_back(nums[i]);
            }
        }
        for(int i = 0; i < positiveElements.size(); i++) {
            res[2*i] = positiveElements[i];
        }
        for(int i = 0; i < negativeElements.size(); i++) {
            res[2*i + 1] = negativeElements[i];
        }
    return res;
    }
};