#include<iostream>
using namespace std;
int wt[100],tat[100],gt[100],gp[100];

int main()
{
    int n;
    double t_wt=0,t_tat=0;
    cout<<"Enter number of process: ";
    cin>>n;
    int p[n],bt[n];
    cout<<"Enter process: ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    cout<<"Enter Cpu time: ";
    for(int i=0; i<n; i++)
    {
        cin>>bt[i];
    }
    int q;
    cout<<"Enter time quantum: ";
    cin>>q;

    int rm_bt[n];
    for(int i=0; i<n; i++)
    {
        rm_bt[i]=bt[i];
    }

    int t=0,j=0,k=0;
    while(1)
    {
        bool done = true;
        for(int i=0; i<n; i++)
        {
            if(rm_bt[i]>0)
            {
                done = false;
                if(rm_bt[i]>q)
                {
                    t+=q;
                    rm_bt[i]-=q;
                    gt[j]=t;
                    gp[j]=i+1;
                    j++;
                }
                else
                {
                    t= t+rm_bt[i];
                    wt[i] = t-bt[i];
                    rm_bt[i] = 0;
                    gt[j]=t;
                    gp[j]=i+1;
                    j++;
                }

            }
        }
        if(done == true)
            break;

    }

    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }

    cout<<"\n\n\n";
    cout<<"   wt  tat";
    cout<<"\n";

    for(int i=0;i<n;i++)
    {
        t_wt+=wt[i];
        t_tat+=tat[i];
        cout<<"process "<<i+1<<" "<<wt[i]<<" "<<tat[i];
        cout<<"\n";
    }
    cout<<"\n\n\n";
    cout<<"0";
    for(int i=0;i<j;i++){
        cout<<"------"<<gt[i];
    }
    cout<<"\n";

    for(int i =0;i<j;i++){

        cout<<"  p"<<gp[i]<<"    ";
    }



    cout<<"\n\n";
    cout<<"average wt: "<<t_wt/n;
    cout<<"\n\n";
    cout<<"average tat: "<<t_tat/n;

    return 0;
}
