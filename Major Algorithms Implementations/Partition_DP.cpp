
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        if(sum%2!=0)
            return 0;
        
        vector<int>dp((sum/2)+1,-1);
       // dp[0]=1;
        
        return helper(0,0,nums,sum/2,dp);
        
       
    }
    
    bool helper(int start,int sum,vector<int>&nums,int target,vector<int>&dp)
    {
        int n=nums.size();
        if(sum==target)
            return 1;
        if(sum>target)
            return 0;
        if(start==n)
            return 0;
        
        if(dp[sum]!=-1)
            return dp[sum];
        
        if(helper(start+1,sum+nums[start],nums,target,dp))
            return dp[sum]=1;
        if(helper(start+1,sum,nums,target,dp))
            return dp[sum]=1;
        
        return dp[sum]=0;
    }
};


