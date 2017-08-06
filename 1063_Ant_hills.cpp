#include<bits/stdc++.h>
using namespace std;

int node, edge, timer=0;

const int sz=1e5+5;

vector<int>adj_list[sz];

int low[sz], dis[sz], articulatio_point[sz], vis[sz], par[sz];

void input(int n, int e)
{
    node = n;
    edge = e;

    for(int i=0; i<edge; i++)
    {
        int u, v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
}

void dfs(int u)
{
    vis[u] = 1;

    dis[u] = low[u] = ++timer;

    int subtree = 0;

    for(int i=0; i<adj_list[u].size(); i++)
    {
        int v = adj_list[u][i];

        if(!vis[v])
        {
            subtree++;
            par[v] = u;
            dfs(v);

            low[u] = min(low[u], low[v]);

            if(par[u]!=-1 && dis[u]<=low[v]) articulatio_point[u]=1;

            if(par[u]==-1 && subtree>1) articulatio_point[u]=1;
        }
        else if(v!=par[u]) low[u] = min(low[u], dis[v]);
    }
}

void reset()
{
    timer = 0;
    memset(par, -1, sizeof par);
    memset(dis, 0, sizeof dis);
    memset(vis, 0, sizeof vis);
    memset(low, 0, sizeof low);
    memset(articulatio_point, 0, sizeof articulatio_point);

    for(int i=1; i<=node; i++) adj_list[i].clear();
}

main()
{
    int test, res=0;

    cin>>test;

    for(int tc=1; tc<=test; tc++)
    {
        cin>>node>>edge;

        reset();

        input(node, edge);

        dfs(1);

        for(int i=1; i<=node; i++)
        {
            if(articulatio_point[i]) res++;
        }

        cout<<"Case "<<tc<<": "<<res<<endl;
        res=0;

        reset();
    }

    return 0;
}
