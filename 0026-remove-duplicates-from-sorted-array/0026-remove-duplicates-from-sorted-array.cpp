class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0, e = 1;
        int l = nums.size();

        while(e < l){
            while(e < l && nums[s] == nums[e])
                ++e;
            if(e == l)
                break;
            nums[++s] = nums[e];
        }
        return ++s;
    }
};
