class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        long int i=0;
        for(i=5; n/i >=1 ;i*=5){
            ans+= n/i;
        }
        return ans;
    }
};