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
        int l=0;int r=n-1;int lmax=0,rmax=0;long long total=0;
        while(l<r)
        {
            if(arr[l]<=arr[r])
            {
                if(lmax<=arr[l])
                lmax=arr[l];
                else
                total+=lmax-arr[l];
                l++;
            }
            else
            {
                if(rmax<=arr[r])
                rmax=arr[r];
                else
                total+=rmax-arr[r];
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