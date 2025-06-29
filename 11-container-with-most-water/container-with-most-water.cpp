class Solution {
public:
    int maxArea(vector<int>& height) {
        // Approach 1 : BruteForce, TC : O(n*2)
        // int maxWaterArea = 0;
        // for(int i=0; i<height.size(); i++){
        //     for(int j= i+1; j<height.size(); j++){
        //         int w = j - i;q 
        //         int ht = min(height[i], height[j]);
        //         int currentWaterArea = w * ht;
        //         maxWaterArea = max(maxWaterArea, currentWaterArea);
        //     }
        // }
        // return maxWaterArea;
        // Approach 2 : Optimal - Two Pointer Approach (TC - O(n))
        int left = 0;
        int right = height.size()-1;
        int maxContainerArea = 0;
        int w, ht, currentArea;
        while(left < right){
            w = right - left;
            ht = min(height[left], height[right]);
            currentArea = w * ht;
            maxContainerArea = max(maxContainerArea, currentArea);
            height[left] < height[right] ? left++ : right--;
        }
        return maxContainerArea;
    }
};