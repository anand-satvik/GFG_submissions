//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node,vector<int> adj[],int vis[],stack<int> &st)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        dfs(it,adj,vis,st);
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    int vis[v]={0};stack<int> st;
	    for(int i=0;i<v;i++)
	    {
	        if(vis[i]==0)
	        dfs(i,adj,vis,st);
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	    
	    
	    
	   // vector<int> indegree(v,0);
	   // for(int i=0;i<v;i++)
	   // {
	   //     for(auto it:adj[i])
	   //     {
	   //         indegree[it]++;
	   //     }
	   // }
	   // queue<int> q;
	   // for(int i=0;i<v;i++)
	   // {
	   //     if(indegree[i]==0)
	   //     q.push(i);
	   // }
	   // vector<int> ans;
	   // while(!q.empty())
	   // {
	   //     int node=q.front();
	   //     q.pop();
	   //     ans.push_back(node);
	   //     for(auto it:adj[node])
	   //     {
	   //         indegree[it]--;
	   //         if(indegree[it]==0)
	   //         q.push(it);
	   //     }
	   // }
	   // return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends