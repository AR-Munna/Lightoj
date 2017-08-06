#include<bits/stdc++.h>

using namespace std;

const int sz = 100005;

vector<int>adj_list[sz];
vector<int>cost[sz];

int  dis[sz], par[sz];

int node, edge;

struct nodes
{
    int u;
    int w;

    nodes(int a, int b)
    {
        u = a;
        w = b;
    }

    bool operator <(const nodes &p) const
    {
        return w>p.w;
    }
};


void input()
{
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        int u, v, w;

        cin>>u>>v>>w;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

        cost[u].push_back(w);
        cost[v].push_back(w);
    }
}

priority_queue<nodes>q;

void dijkstra()
{
    memset(dis, 1, sizeof dis);

    q.push(nodes(1,0));

    dis[1] = 0;

    while(!q.empty())
    {
        nodes top = q.top();
        q.pop();

        int u = top.u;

        for(int i=0; i<adj_list[u].size(); i++)
        {
            int v = adj_list[u][i];

            if(dis[v]>dis[u]+cost[u][i])
            {
                dis[v] = dis[u]+cost[u][i];
                par[v] = u;
                q.push(nodes(v,dis[v]));
            }
        }
    }
}

void reset()
{
    for(int i=0; i<sz; i++) adj_list[i].clear();
    for(int i=0; i<sz; i++) cost[i].clear();
    while(!q.empty()) q.pop();
}

main()
{
    int test, res;

    cin>>test;

    for(int tc=1; tc<=test; tc++)
    {
        input();

        cout<<"Case "<<tc<<": ";

        dijkstra();

        //for(int i=0; i<node; i++)cout<<dis[i]<<endl;
        cout<<dis[node]<<endl;

        reset();
    }

    return 0;
}
