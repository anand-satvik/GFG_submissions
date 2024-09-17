//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    long long trappingWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        long long lmax=0,rmax=0,total=0;
        long long l=0,r=n-1;
        while(l<r)
        {
            if(arr[l]<=arr[r])
            {
                if(lmax>arr[l])
                {
                    total+=lmax-arr[l];
                }
                else
                lmax=arr[l];
                l++;
            }
            else
            {
                if(rmax>arr[r])
                total+=rmax-arr[r];
                else
                rmax=arr[r];
                r--;
            }
        }
        return total;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;

        vector<int> a(n);

        // adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a) << endl;
    }

    return 0;
}
// } Driver Code Ends