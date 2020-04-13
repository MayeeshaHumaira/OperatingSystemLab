#include<bits/stdc++.h>
using namespace std;

int P,R;

int main(){
    cout<<"Enter number of Processes: ";
    cin>>P;

    cout<<"Enter number of Resources: ";
    cin>>R;

    int proc[P];
    cout<<"Enter Processes:\n";
    for(int i=0;i<P;i++){
            cin>>proc[i];
        }


    int maxm[P][R];
    cout<<"Enter Maximum:\n";
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            cin>>maxm[i][j];
        }
    }

    int allo[P][R];
    cout<<"Enter Allocation:\n";
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            cin>>allo[i][j];
        }
    }

    int totalRes[R];
    cout<<"Enter Total Resources:\n";
    for(int i=0;i<R;i++){
            cin>>totalRes[i];
        }

     int avail[R];
     int t;
     int totalAllo[R];
    for(int i=0;i<R;i++){
            t=0;
        for(int j=0;j<P;j++){
            t+=allo[j][i];
        }
        totalAllo[i]=t;

    }
    for(int i=0;i<R;i++){
        avail[i]=totalRes[i]-totalAllo[i];
    }


    int need[P][R];
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            need[i][j]=maxm[i][j]-allo[i][j];
        }
    }

    bool finish[P]={0};
    int safeseq[P];
    int work[R];
    for(int i=0;i<R;i++){
        work[i]=avail[i];
    }

    int count =0;
    while(count<P){
        bool found =false;
        for(int p=0;p<P;p++){
            if(finish[p]==0){
                int j;
                for(j=0;j<R;j++){
                    if(need[p][j]>work[j]){
                        break;
                    }
                }

                if(j==R){
                    for(int i=0;i<R;i++){
                        work[i]+=allo[p][i];
                    }
                    safeseq[count++]=p;
                    found = true;
                    finish[p]=1;
                }
            }
        }
        if(found == false){
            cout<<"System is Not Safe";
            return 0;
        }
    }

    cout<<"The safe sequence is: ";
    for(int i=0;i<P;i++){
        cout<<safeseq[i]<<"->";
    }



    return 0;
}
