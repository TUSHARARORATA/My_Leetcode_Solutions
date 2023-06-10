class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    { vector<int>dp(amount+1,amount+1);
   dp[0]=0;
   sort( begin(coins) , end(coins));
   for( auto i=0 ;i<=amount ;i++)
   {
       for( auto j=0 ; j<coins.size() ;j++)
       {
           if(i-coins[j]>=0)
           {
               dp[i]=min( dp[i] , dp[i-coins[j]]+1);
           }
       }
   }
   /*for ( auto i =0;i<=amount ;i++)
   {
       cout<<dp[i]<<" ";
   }*/
   if(dp[amount]!=amount +1)
   return dp[amount];
   else return (-1);

        
        
    }
};