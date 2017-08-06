#include<bits/stdc++.h>

using namespace std;

int row, column;

char grid[21][21];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int res, cnt, vis[1005][1005];

bool valid(int x, int y)
{
    if((x>=0 && x<row) && (y>=0 && y<column) && grid[x][y]=='.') return true;
    else return false;
}

void dfs(int u, int v)
{
    cnt++;

    vis[u][v] = 1;

    for(int i=0; i<4; i++)
    {
        int x = u + dx[i];
        int y = v + dy[i];

        if(valid(x,y) && vis[x][y]==0)
        {
            vis[x][y] = 1;
            dfs(x,y);
        }
    }
}

main()
{
    int test, tc, x, y;

    cin>>test;

    for(tc=1; tc<=test; tc++)
    {
        cin>>column>>row;

        memset(vis, 0, sizeof vis);

        getchar();

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                grid[i][j] = getchar();

                if(grid[i][j]=='@')
                {
                    x = i;
                    y = j;
                    vis[x][y] = 1;
                }
            }
            getchar();
        }

        cnt = 0;

        dfs(x,y);

        cout<<"Case "<<tc<<": "<<cnt<<endl;
    }

    return 0;
}
