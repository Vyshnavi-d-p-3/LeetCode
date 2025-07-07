class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    // Approach 1 : TLE Error
    // vector<int> result;
    // bool found = false;
    //  for(int i = 0; i < temperatures.size(); i++) {
    //     found = false;
    //     for(int j = i + 1 ; j < temperatures.size(); j++){
    //         if(temperatures[i] < temperatures[j]) {
    //             result.push_back(j - i);
    //             found = true;
    //             break;
    //         }
    //     }
    //     if(!found){
    //         result.push_back(0);
    //     }
    //  } 
    //  return result;

    // Approach 2 : Using Stack Data Structure
    // stack<int> st;
    // vector<int> res(temperatures.size(), 0);
    // for(int i = 0; i < temperatures.size(); i++){
    //     while(!st.empty() && temperatures[i] > temperatures[st.top()]){
    //         int idx = st.top(); st.pop();
    //         res[idx] = i - idx;
    //     }
    //     st.push(i);
    // }
    // return res;

    // Approach 3 : using 
    vector<int> results(temperatures.size());
    stack<int> stack;
    for(int i = 0; i < temperatures.size(); i++){
        while(!stack.empty() && temperatures[stack.top()] < temperatures[i]){
            results[stack.top()] = i - stack.top();
            stack.pop();
        }
        stack.push(i);
    }
    return results;
    }
};