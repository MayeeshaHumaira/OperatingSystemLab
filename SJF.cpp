#include<bits/stdc++.h>
using namespace std;
int wt[100],tat[100];
struct process{
    int pid;
    int bt;
};
bool comp(process a, process b){
    return(a.bt<b.bt);
}

int main()
{
    int n;
    cout<<"no of process ";
    cin>>n;
    struct process p[n];
    cout<<"Enter process: ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].pid;
    }
    cout<<"Enter the CPU times ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].bt;
    }
    sort(p,p+n,comp);
    cout<<"\n";


    wt[0]=0;
    for(int i=1; i<n; i++)
    {
        wt[i]=p[i-1].bt+wt[i-1];
    }

    for (int i = 0; i < n ; i++)
        tat[i] = p[i].bt + wt[i];


    int total_wt=0, total_tat=0;

        for(int i=0; i<n; i++)
        {
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];


        }
        cout<<"0";
        for(int i=0;i<n;i++){
            cout<<"___P"<<p[i].pid<<"___"<<tat[i];
        }

        cout<<"\n";
        cout<<"Average WT: "<<total_wt/n;
        cout<<"Average TAT: "<<total_tat/n;

    return 0;
}


