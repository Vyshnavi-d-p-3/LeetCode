class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    // Brute Force that have Time Complexity as O(n*2) and space complexity O(1)--> Constant Space
    //    vector<int> result;
    //    int product;
    //    for(int i =0 ;i<nums.size();i++){
    //     product = 1;
    //     for(int j = 0; j < nums.size();j++){
    //         if(i != j) {
    //             product = product * nums[j];
    //         }
    //     }
    //     result.push_back(product);
    //    }
    //    return result;

    // Approach 2 - where we will maintain two arrays preffix and suffix and calculate the product
    int n = nums.size();
    vector<int> output(n);
    vector<int> left_product(n);
    vector<int> right_product(n);
    left_product[0] = 1;
    right_product[n-1] = 1;
    for(int i = 1; i < n ; i++)
    {
        left_product[i] = left_product[i-1] * nums[i-1];
    }
    for(int i = n-2; i >= 0; i--){
        right_product[i] = right_product[i+1] * nums[i+1];
    }
    for(int i=0; i<nums.size() ;i++){
        output[i] = left_product[i]*right_product[i];
    }
    return output;
    }
};