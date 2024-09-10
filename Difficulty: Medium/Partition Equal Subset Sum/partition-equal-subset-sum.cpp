//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int nums[])
    {
        // code here
        // int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        if(total%2)
        return 0;
        else{
            int target=total/2;
            vector<vector<int>> dp(n,vector<int> (target+1,0));
            for(int i=0;i<n;i++) dp[i][0]=true;
            if(nums[0]<=target) dp[0][nums[0]]=true;
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<=target;j++)
                {
                    int notTake=dp[i-1][j];
                    int take=0;
                    if(nums[i]<=j)
                    {
                        take=dp[i-1][j-nums[i]];
                    }
                    dp[i][j]=take | notTake;
                }
                
            }
            return dp[n-1][target];
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends