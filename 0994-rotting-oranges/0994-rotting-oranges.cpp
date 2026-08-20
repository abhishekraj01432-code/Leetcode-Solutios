class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>status(m,vector<int>(n,-1));
        queue<pair<int,int>>Q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    Q.push({i,j});
                    status[i][j]=0;
                }
            }
        }
    while(!Q.empty())
    {
       pair<int,int>p;
       p=Q.front();
       Q.pop();
       int i=p.first;
       int j=p.second;
       //UP
       if(i-1>=0)
       {
        if(grid[i-1][j]==1)
        {
            grid[i-1][j]=2;
            status[i-1][j]=status[i][j]+1;
            Q.push({i-1,j});
        }
       }
       //DOWN
       if(i+1<m)
       {
        if(grid[i+1][j]==1)
        {
            grid[i+1][j]=2;
            status[i+1][j]=status[i][j]+1;
            Q.push({i+1,j});
        }
       }
       //LEFT
       if(j-1>=0)
       {
        if(grid[i][j-1]==1)
        {
            grid[i][j-1]=2;
            status[i][j-1]=status[i][j]+1;
            Q.push({i,j-1});
        }
       }
       //RIGHT
       if(j+1<n)
       {
        if(grid[i][j+1]==1)
        {
            grid[i][j+1]=2;
            status[i][j+1]=status[i][j]+1;
            Q.push({i,j+1});
        }
       }
    }
    int maximum=0;
     for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                return-1;
                if(grid[i][j]==2)
                {
                    if(status[i][j]>maximum)
                    maximum=status[i][j];
                }
             }
         }
         return maximum;
    }
};