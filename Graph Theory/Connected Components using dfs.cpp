/*Accepted, Submission Link: https://www.codechef.com/viewsolution/44978282 */
#include <bits/stdc++.h>

using namespace std;

int vertex, edge, u, v, len;
vector<bool>visited;
vector< vector<int> > adjList;

void getAdjList()
{
    cin>>vertex>>edge;
    adjList.resize(vertex + 1);
    visited.resize(vertex + 1);
    for(int i = 0; i <= vertex; i++) visited[i] = false;
    for(int i = 0; i < edge; i++)
    {
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

int dfs(int source)
{
    stack<int> st;

    st.push(source);

    while(!st.empty())
    {
        u = st.top();
        if(visited[u])
        {
            st.pop();
            continue;
        }
        int len = adjList[u].size();
        for(int i = 0; i < len; i++)
        {
            v = adjList[u][i];
            if(!visited[v]) st.push(v);
        }
        visited[u] = true;
    }
    return 1;
}

void solve()
{
    adjList.clear();
    visited.clear();
    getAdjList();
    int cnt = 0;
    for(int i = 0; i < vertex; i++)
    {
        if(!visited[i]) cnt += dfs(i);
    }
    cout<<cnt<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t; cin>>t;
    //int i = 1; while(i <= t) cout<<"Case "<<i++<<": "<<endl, solve();
    while(t--)
    solve();

    return 0;
}

