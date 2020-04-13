#include<iostream>
using namespace std;
int wt[100],tat[100];

int main()
{
    int n;
    cout<<"no of process ";
    cin>>n;
    int bt[n],a[n];
    cout<<"Enter the CPU times ";
    for(int i=0; i<n; i++)
    {
        cin>>bt[i];
    }
    cout<<"\n";


    wt[0]=0;
    for(int i=1; i<n; i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
    }

    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];


    int total_wt=0, total_tat=0;

        for(int i=0; i<n; i++)
        {
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];


        }
        cout<<"0";
        for(int i=0;i<n;i++){
            cout<<"___P"<<i+1<<"___"<<tat[i];
        }

        cout<<"\n";
        cout<<"Average WT: "<<total_wt/n;
        cout<<"Average TAT: "<<total_tat/n;

    return 0;
}


