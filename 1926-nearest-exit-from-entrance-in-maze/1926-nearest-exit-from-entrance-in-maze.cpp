class Solution {
public:
    bool isValid(vector<vector<char>>& maze,vector<vector<bool>>& vis, int i,int j){
        if(i>=0 and j>=0 and i<=maze.size()-1 and j<=maze[0].size()-1 and maze[i][j]=='.' and vis[i][j]==0){
            return 1;
        }
        return 0;
    }
    bool isEnd(vector<vector<char>>& maze, int i,int j){
        if(i==0 or j==0 or i==maze.size()-1 or j==maze[0].size()-1){
            return 1;
        }
        return 0;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        vector<vector<bool>>vis(maze.size(),vector<bool>(maze[0].size(),0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{entrance[0],entrance[1]},1});
        vis[entrance[0]][entrance[1]]=1;
        
        int ii[]={0,0,1,-1};
        int jj[]={1,-1,0,0};
        
        while(q.size()){
            int cnt=q.front().second;
            int i=q.front().first.first;
            int j=q.front().first.second;
            q.pop();
            // cout<< i<<" "<<j<<endl;
            for(int k=0;k<4;k++){
                if(isValid(maze,vis,i+ii[k],j+jj[k])){
                    if(isEnd(maze,i+ii[k],j+jj[k])){
                        return cnt;
                    }
                    vis[i+ii[k]][j+jj[k]]=1;
                    q.push({{i+ii[k],j+jj[k]},cnt+1});
                }
            }
        }
        return -1;
    }
};