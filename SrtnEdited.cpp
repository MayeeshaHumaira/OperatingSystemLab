#include<bits/stdc++.h>
using namespace std;

int wt[100],tat[100],com[100];

int main()
{
    int n,smallest,count =0;
    int at[10],bt[10],rm_t[10];
    double end,t_wt,t_tat;
    cout<<"Enter number of process: ";
    cin>>n;


    cout<<"Enter arrival time:";
    for(int i=0; i<n; i++)
    {
        cin>>at[i];
    }
    cout<<"Enter Burst time:";
    for(int i=0; i<n; i++)
    {
        cin>>bt[i];
    }

    for(int i=0; i<n; i++)
    {
        rm_t[i]=bt[i];
    }

    bt[9]=INT_MAX;
    for(int time=0; count!=n; time++)
    {
        smallest = 9;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0 )
                smallest=i;
        }
        bt[smallest]--;
        if(bt[smallest]==0){
            count++;
            end = time+1;
            com[smallest]= end;
            wt[smallest]=end-at[smallest]-rm_t[smallest];
            tat[smallest]=end-at[smallest];
            //tat[smallest] = end - at[smallest];
        }
    }
    for(int i=0;i<n;i++){
        t_wt+=wt[i];
        t_tat+= tat[i];
        cout<<i+1<<"  "<<com[i];
    }

    cout<<"\n\n\n";

    //cout"\n\n\n";
    cout<<" Average WT: "<<t_wt/n;
    cout<<"\n";
    cout<<" Average TAT: "<<t_tat/n;


    return 0;
}
