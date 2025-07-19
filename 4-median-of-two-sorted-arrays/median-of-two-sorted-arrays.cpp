class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Approach 1: Merge and sort and find the median
        // // Get the sizes of both input arrays.
        // int n = nums1.size();
        // int m = nums2.size();

        // // Merge the arrays into single sorted array
        // vector<int> merged;
        // for(int i = 0; i < n; i++){
        //     merged.push_back(nums1[i]);
        // }
        // for(int i = 0; i < m; i++){
        //     merged.push_back(nums2[i]);
        // }
        
        // // Sort the merged array.
        // sort(merged.begin(), merged.end());

        // // Calculate the total number of elements in the merged
        // int total = merged.size();

        // if(total % 2 == 1) {
        //     return static_cast<double>(merged[total/2]);
        // } else {
        //     // If the total number of elemebt is even, Calculate the average of the two middle elements as the median
        //     int middle1 = merged[total/2 - 1];
        //     int middle2 = merged[total / 2];
        //     return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
        // }
        // Approach 2 : Two-Pointer Method
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, m1 = 0, m2 = 0;
        // Find Median.
        for(int count = 0; count <= (n + m) / 2; count++) {
            m2 = m1;
            if(i != n && j != m) {
                if(nums1[i] > nums2[j]) {
                    m1 = nums2[j++];
                } else {
                    m1 = nums1[i++];
                }
            } else if (i < n) {
                m1 = nums1[i++];
            } else {
                m1 = nums2[j++];
            }
        }

        // Check if the sum of n and m is odd.
        if((n + m) % 2 == 1) {
            return static_cast<double>(m1);
        } else {
            double ans = static_cast<double>(m1) + static_cast<double>(m2);
            return ans / 2.0;
        }
    }
};