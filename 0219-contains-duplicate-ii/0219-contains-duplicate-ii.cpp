// Time Complexity : O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Create a Set for storing previous of k elements...
        unordered_set<int> hset;
        // Traverse for all elements of the given array in a for loop...
        for(int idx = 0; idx < nums.size(); idx++) {
            // Check if set already contains nums[idx] or not...
            // If duplicate element is present at distance less than equal to k, return true...
            if(hset.count(nums[idx]))
                return true;
            // Otherwise, add nums[idx] to the set...
            hset.insert(nums[idx]);
            // If size of the set becomes greater than k...
            if(hset.size() > k)
                // Remove the last visited element from the set...
                hset.erase(nums[idx - k]);
        }
        // If no duplicate element is found then return false...
        return false;
    }
};