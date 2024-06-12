class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
//Method 2 using count of each number
   
    //  int c0=0,c1=0,c2=0;
    //  for(int i=0;i<nums.size();i++){
    //      if(nums[i]==0)
    //      c0++;
    //      if(nums[i]==1)
    //      c1++;
    //      if(nums[i]==2)
    //      c2++;
    //  }
    //  for(int i=0;i<c0;i++){
    //      nums[i]=0;
    //  }
    //  for(int i=c0;i<c0+c1;i++){
    //      nums[i]=1;
    //  }
    //  for(int i=c0+c1;i<nums.size();i++){
    //      nums[i]=2;
    //  }



//Method 3 Using basic sort function
 //     // sort(nums.begin(),nums.end());
    }
};