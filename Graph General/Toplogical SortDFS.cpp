class Solution
{
    public:

    void DFSRec(int s,stack<int>&st,vector<bool>&visited,vector<int>adj[] ){
        visited[s] = true;

        vector<int>data = adj[s]; // source data 
        for(auto v : data){
            if(!visited[v]){
               DFSRec(v,st,visited,adj); 
            }
        }
        st.push(s);
    }
    vector<int> toposort(int v , vector<int>adj[])

    stack<int>st;
    vector<bool>visited(V,visited);

    for(int i = 0; i<V; i++){
        if(!visited[i]){
            DFSRec(i,st,visited,adj);

        }
    }

    vector<int>ans;
    while(!st.empty()){
        int x = st.top();
        st.pop();
        ans.push_back(x);
    }
    return ans;

}

