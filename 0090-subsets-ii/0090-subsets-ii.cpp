class Solution {
private:
    vector<vector<int>> ans;
    vector <int> temp;
    void helper(int idx,vector<int>& nums){
        ans.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            helper(i+1,nums);
            temp.pop_back();
        }
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(0,nums);
        return ans;
    }
};