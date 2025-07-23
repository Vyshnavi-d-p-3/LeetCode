class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Approach 1 : Brute Force  - TC : O(n*m), SC : O(n+m)
        vector<int> res;
        vector<int> flag(nums2.size(), 0);
        set<int> inserted;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j] && flag[j] == 0 && inserted.count(nums1[i]) == 0) {
                    res.push_back(nums1[i]);
                    flag[j] = 1;
                    inserted.insert(nums1[i]);
                }
            }
           
        }
 return res;


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
        
        // Approach 2 : Using Set - TC : O(N+M), SC : O(N)
        // unordered_set<int> hashset(nums1.begin(), nums1.end());
        // unordered_set<int> result;
        // for(int num : nums2) {
        //     if(hashset.count(num)) {
        //         result.insert(num);
        //     }
        // }
        // return vector<int>(result.begin(), result.end());
    }
};