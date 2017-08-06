#include<bits/stdc++.h>
using namespace std;

const int sz = 300005;

vector<int>adj_list[sz];
vector<int>cost[sz];

int vis[sz], dis[sz];

void bfs(int u)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));

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
                vis[cur] = 1;
                dis[cur] = dis[v] + cost[v][i];
                q.push(cur);
            }
        }
    }
}

main()
{
    int test, node;

    cin>>test;

    for(int tc=1; tc<=test; tc++)
    {
        cin>>node;

        for(int i=0; i<node-1; i++)
        {
            int u, v, w;

            cin>>u>>v>>w;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);

            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        bfs(0);

        int mx=0, indx;

        for(int i=0; i<node; i++)
        {
            if(dis[i]>mx)
            {
                mx = dis[i];
                indx = i;
            }

        }
        //cout<<endl<<mx<<endl;
        bfs(indx);

        mx = 0;

        for(int i=0; i<node; i++)
        {
            if(dis[i]>mx)
            {
                mx = dis[i];
                //mx = dis[i];
            }
        }

        cout<<"Case "<<tc<<": "<<mx<<endl;

        for(int i=0; i<node; i++) adj_list[i].clear();
        for(int i=0; i<node; i++) cost[i].clear();
    }

    return 0;
}
