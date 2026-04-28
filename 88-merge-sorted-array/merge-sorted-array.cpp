class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        vector<int> nums3;
        int left = 0;
        int right = 0;

        while (left < n && right < m) {
            if (nums1[left] <= nums2[right]) {
                nums3.push_back(nums1[left]);
                left++;
            } else {
                nums3.push_back(nums2[right]);
                right++;
            }
        }

        while (left < n) {
            nums3.push_back(nums1[left]);
            left++;
        }

        while (right < m) {
            nums3.push_back(nums2[right]);
            right++;
        }

        for (int i = 0; i < n + m; i++) {
            nums1[i] = nums3[i];
        }
    }
};