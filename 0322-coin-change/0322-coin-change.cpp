class Solution {
public:
    int coinChange(vector<int>& coins, int tar) {
        int n=coins.size();
        
        if(tar==0) return 0;
        vector<vector<int>> dp(n+1,vector<int> (tar+1,-1));
        for(int i=0;i<n+1;i++)
        {
           dp[i][0]=0;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<tar+1;j++)
            {
                if(j>=coins[i-1])
                {
                    if(dp[i][j-coins[i-1]]!=-1 && dp[i-1][j]!=-1)
                        dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                     else if(dp[i-1][j]!=-1)
                         dp[i][j]=dp[i-1][j];
                    else if(dp[i][j-coins[i-1]]!=-1)
                        dp[i][j]=dp[i][j-coins[i-1]]+1;
                }
                else
                    
                dp[i][j]=dp[i-1][j];
                 
            }
        }
        return dp[n][tar];
        
    }
};