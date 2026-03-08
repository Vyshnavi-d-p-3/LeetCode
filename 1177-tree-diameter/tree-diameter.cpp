class Solution {
public:
    pair<int,int> solve(unordered_map<int,vector<int>> graph,int src){
        queue<int> q;
                unordered_set<int> us;

        q.push(src);
        us.insert(src);
        vector<int> tmpv;
        int cnt=0;
        while(!q.empty()){
            int qs=q.size();
            tmpv.clear();
            cnt++;

            for(int i=0;i<qs;i++){
                int tmp=q.front();
                q.pop();
                cout<<tmp<<endl;
                tmpv.push_back(tmp);
                for(auto nbr:graph[tmp]){
                    cout<<"nbr<<"<<nbr<<endl;
                    if(us.find(nbr)==us.end()){
                        q.push(nbr);
                                        us.insert(nbr);

                    }
                }
            }
        }
        return {tmpv[0],cnt};
    }
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        if(edges.size()==0)return 0;
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        pair<int,int> v=solve(graph,edges[0][0]);
        cout<<v.first<<" "<<v.second<<endl;
        pair<int,int> v1=solve(graph,v.first);

        return v1.second-1;
        
    }
};