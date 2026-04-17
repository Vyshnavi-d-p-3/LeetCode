class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> res(0);
       sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const      vector<int>& b){return a[0] < b[0];});
       res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            int n = res.size()-1;
            int currEnd = res[n][1];
            if(currEnd >= intervals[i][0]){
                res[n][1] = max(currEnd,intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};