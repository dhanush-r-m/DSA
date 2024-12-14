class Solution
{
	public:

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    queue<int>q;
	    
	    vector<int> indegree(V, 0);
	    for(int i=0; i<V; i++){
	        vector<int> data = adj[i];
	        for(auto x: data){
	            indegree[x]++;
	        }
	    }
	    
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(! q.empty()){
	        int u = q.front();
	        q.pop();
	        ans.push_back(u);
	        
	        for(auto v: adj[u]){
	            indegree[v]--;
	            if(indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    
	    return ans;
	}
};