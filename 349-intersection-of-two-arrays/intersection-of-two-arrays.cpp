class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Approach 1 : Using Unordered Set - TC : O(N), SC : O(N+M)
        // unordered_set<int> set1(nums1.begin(), nums1.end());
        // unordered_set<int> set2(nums2.begin(), nums2.end());
        // vector<int> result;
        // for(const auto& num : set1) {
        //     if(set2.find(num) != set2.end()) {
        //         result.push_back(num);
        //     }
        // }
        // return result;
        
        unordered_set<int> hashset(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for(int num : nums2) {
            if(hashset.count(num)) {
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};