class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        vector<set<int>> online;
        DSU(int n) {
            parent.resize(n+1);
            size.resize(n+1,1);
            online.resize(n+1);
            for(int i=1;i<=n;i++){
                parent[i]=i;
                online[i].insert(i);
            }
        }
        int find(int x){
            return parent[x]==x?x:parent[x]=find(parent[x]);
        }
        void unite(int x,int y){
            x=find(x);
            y=find(y);
            if(x==y) return;
            if(size[x]<size[y]) swap(x,y);
            parent[y]=x;
            size[x]+=size[y];
            online[x].insert(online[y].begin(),online[y].end());
            online[y].clear();
        }
        void offline(int x){
            online[find(x)].erase(x);
        }
        int getMinOnline(int x){
            int p=find(x);
            if(online[p].empty()) return -1;
            return *online[p].begin();
        }
        bool isOnline(int x){
            return online[find(x)].count(x);
        }
    };
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries){
        DSU dsu(c);
        for(auto &conn: connections){
            dsu.unite(conn[0],conn[1]);
        }
        vector<int> ans;
        for(auto &q: queries){
            if(q[0]==1){
                int x=q[1];
                ans.push_back(dsu.isOnline(x)?x:dsu.getMinOnline(x));
            }else{
                dsu.offline(q[1]);
            }
        }
        return ans;
    }
};
