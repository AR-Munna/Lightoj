#include<bits/stdc++.h>

using namespace std;

const int sz = 105;

vector<int>adj_list[sz];

int dis[sz], par[sz], vis[sz], dis2[sz];


int node, timer, edge;

void initialize()
{
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<node; i++) adj_list[i].clear();
    //while(!q.empty()) q.pop();
}

inline void bfs(int u)
{
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));

    vis[u] = 1;

    dis[u] = 0;

    queue<int>q;

    q.push(u);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int i=0; i<adj_list[v].size(); i++)
        {
            int cur = adj_list[v][i];

            if(!vis[cur])
            {
                q.push(cur);
                dis[cur] = dis[v]+1;
                vis[cur] = 1;
            }
        }
    }
}

main()
{

    int test, source, dest;

    cin>>test;

    for(int j=1; j<=test; j++)
    {
        initialize();

        cin>>node>>edge;

        for(int i=0; i<edge; i++)
        {
            int u, v;

            cin>>u>>v;

            adj_list[u].push_back(v);

            adj_list[v].push_back(u);
        }

        cin>>source>>dest;

        bfs(source);

        for(int i=0; i<node; i++)
        {
            dis2[i]=dis[i];
        }

        bfs(dest);

        int ans = INT_MIN;

        for(int i=0; i<node; i++) ans = max(ans, dis[i]+dis2[i]);

        cout<<"Case "<<j<<": "<<ans<<endl;
    }

    return 0;
}

