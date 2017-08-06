#include<bits/stdc++.h>

using namespace std;

const int sz = 100005;

vector<int>adj_list[sz];
vector<int>cost[sz];

long long  dis[sz], par[sz];

int node, edge;

struct nodes
{
    int u;
    int w;

    nodes(){}

    nodes(int u, int w):u(u), w(w){}

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

int dijkstra(int n)
{
    memset(dis, 1, sizeof dis);
    memset(par, -1, sizeof par);

    q.push(nodes(1,0));

    dis[1] = 0;

    while(!q.empty())
    {
        nodes top = q.top();
        q.pop();

        int u = top.u;

        if(u==n) return dis[n];

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
    return -1;
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

        res = dijkstra(node);

        if(res==-1) puts("Impossible");

        else cout<<res<<endl;

        reset();
    }

    return 0;
}
