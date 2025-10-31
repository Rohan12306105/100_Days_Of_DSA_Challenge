/*
https://leetcode.com/problems/swim-in-rising-water/solutions/6947295/dsu-implementation-100-beats-c-kindly-upvote

can be solved using djikstra
*/

class Disjoint_set{
    vector<int>parent,rank,size;
public:
    Disjoint_set(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int findParent(int node){
        if(parent[node]==node)
        return node;
        else
        return parent[node]=findParent(parent[node]);
    }
    void UnionBySize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)
            return;
        
           if(size[pu]>size[pv]){
				parent[pv]=pu;
				size[pu]+=size[pv];
			}
			else
			parent[pu]=pv;
			size[pv]+=size[pu];
        }
    
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        Disjoint_set ds(grid.size()*grid.size());
        vector<tuple<int,int,int>> helper;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                helper.push_back({grid[i][j],i,j});
            }
        }
        int n=grid.size();
        // vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<bool>visited(n*n,false);
        sort(helper.begin(),helper.end());
        vector<int>delrow={0,0,1,-1};
        vector<int>delcol={-1,1,0,0};
        for(auto &[height,row,col]:helper){
            // int height=help[0];
            // int row=help[1];
            // int col=help[2];
            // visited[row][col]=1;// maintaining the time ..
            int index1=grid.size()*row+col;
             visited[index1]=true;
        
        for(int i=0;i<4;i++){
            int newRow=row+delrow[i];
            int newCol=col+delcol[i];
            if(newRow>=0 && newCol >=0 && newRow<n && newCol<n && visited[n*newRow+newCol]){
                int index2=grid.size()*newRow+newCol;
                ds.UnionBySize(index1,index2);
            }
        }
        if(ds.findParent(0)==ds.findParent(n*n-1))
        return height;
        }
        return -1;
    }
};