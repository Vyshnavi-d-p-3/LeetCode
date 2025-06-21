class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    // Approach 1 : Brute Force Time Complexity is O(N*2)
    //     int n = numbers.size();
    //     vector<int> result;
    //     for(int i=0; i < n; i++){
    //         int ind1 = i;
    //         for(int j = i+1 ; j < n; j++){
    //             if(numbers[i] + numbers[j] == target){
    //                 result.push_back(i+1);
    //                 result.push_back(j+1);
    //                 break;
    //             }
    //         }
    //     }
    // return result;

    // Approach 2 : Two Pointer approach - Time Complexity is O(N)
        // int n = numbers.size();
        // int left  = 0;
        // int right = n-1;
        // vector<int> result;
        // int sum ;
        // while(left < right){
        //     sum = numbers[left] + numbers[right];
        //     if(sum == target) {
        //        return {left+1 , right+1}; // 1-based Indexing
        //     }
        //     else if(sum < target) left++;
        //     else{
        //         right--;
        //     }
        // }
        // return {};
    // Approach 3 : Using HashMap
        unordered_map<int, int> seen;
        for(int i = 0; i < numbers.size(); ++i){
            int complement = target - numbers[i];
            if(seen.count(complement)) 
                return {seen[complement]+1 , (i+1)};
            seen[numbers[i]] = i ;
        }
        return {};
    }
};