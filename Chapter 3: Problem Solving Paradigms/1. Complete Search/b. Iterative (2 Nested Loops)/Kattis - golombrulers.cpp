class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        search(nums, result, subset, 0);
        return result;
    }
private:
    void search(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int k) {
        if (k == nums.size()) {
            result.push_back(subset);
        } else {
            if (k > 0 && nums[k] == nums[k - 1]) {
                search(nums, result, subset, k + 1);
            } else {
                search(nums, result, subset, k + 1);
                subset.push_back(nums[k]);
                search(nums, result, subset, k + 1);
                subset.pop_back();
            }
        }
    }
};