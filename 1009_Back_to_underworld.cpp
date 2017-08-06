#include<bits/stdc++.h>
using namespace std;

int node;

const int sz = 100005;

vector<int>adj_list[sz];

int vis[sz];

int lykan, vampire;

void dfs(int u, int c)
{
    vis[u] = 2;

    if(c==0) lykan +=1;
    else vampire +=1;

    for(int i=0; i<adj_list[u].size(); i++)
    {
        int v = adj_list[u][i];

        if(vis[v]==1) dfs(v, (c+1)%2);
    }
}

main()
{
    int test, tc, ans=0;

    cin>>test;

    for(int tc=1; tc<=test; tc++)
    {
        cin>>node;
        memset(vis, 0, sizeof(vis));

        for(int i=0; i<node; i++)
        {
            int u, v;
            cin>>u>>v;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
            vis[u] = 1;
            vis[v] = 1;
        }

        for(int i=1; i<=20005; i++)
        {
            if(vis[i]==1)
            {
                lykan=vampire=0;
                dfs(i,0);
                ans += max(lykan,vampire);
            }
        }

        cout<<"Case "<<tc<<": "<<ans<<endl;

        for(int i=0; i<20005; i++) adj_list[i].clear();
        ans = 0;
    }

    return 0;
}
