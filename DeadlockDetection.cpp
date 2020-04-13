#include<bits/stdc++.h>
using namespace std;
#define W 0
#define G 1
#define B 2
int n,e;
vector<int> ar[1000];
vector<int> cycle_path;
int color[1000];
int par[1000];
bool cycle_found = false;

void DFS(int u)
{
    color[u]=G;
    for(int i=0; i<ar[u].size(); i++)
    {
        int v=ar[u][i];
        if(color[v]==G)
        {
            cycle_found = true;
            int temp = u;
            cycle_path.push_back(v);
            while(temp!=v)
            {
                cycle_path.push_back(temp);
                temp = par[temp];
            }
            return;
        }
        if(color[v]==W)
        {
            par[v]=u;
            DFS(v);
        }
    }
    color[u]=B;
}


int main()
{
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int x,y;
        char c1,c2;
        cin>>c1>>c2;
        x=c1-'a'+1;
        y=c2-'a'+1;
        ar[x].push_back(y);
    }

    for(int i=1; i<=n; i++)
    {
        if(color[i]==W)
        {
            DFS(i);
        }
    }
    if(cycle_found)
    {
        cout<<"Deadlock Detected\n";
        for(int i=0; i<cycle_path.size(); i++)
        {
            char x=cycle_path[i]+'a'-1;
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"Deadlock not Detected\n";

    }
    return 0;
}
