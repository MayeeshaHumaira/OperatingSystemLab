#include<bits/stdc++.h>
using namespace std;

int blockSize[100],memReq[100],m,n;

int main(){
    cout<<"Enter no. of memory request: ";
    cin>>m;

    cout<<"Mem Req: ";
    for(int i=0;i<m;i++){
        cin>>memReq[i];
    }


    cout<<"Enter no. of blocks: ";
    cin>>n;

    cout<<"Block sizes: ";
    for(int i=0;i<n;i++){
        cin>>blockSize[i];
    }

    int allocation[m];
    for(int i=0;i<m;i++){
        allocation[i]=-1;
    }

    for(int i=0;i<m;i++){
            int wstIdx = -1;
        for(int j=0;j<n;j++){
            if(blockSize[j]>=memReq[i]){
                if(wstIdx == -1)
                    wstIdx=j;
                else if(blockSize[wstIdx]<blockSize[j])
                    wstIdx=j;
            }

        }
        if(wstIdx!=-1){
            allocation[i]=wstIdx;
            blockSize[wstIdx]-=memReq[i];
        }
        cout<<memReq[i]<<"  ";
        if(allocation[i]!=-1)
        {
            for(int k=0; k<n; k++)
            {
                cout<<blockSize[k]<<"  ";
            }
        }
        else
        {
            int sum =0;
             for(int k=0; k<n; k++)
            {
                sum+=blockSize[k];
            }
            cout << "Not Allocated  External Fragmentation:"<<sum;


        }
        cout<<"\n";

    }





    return 0;

}
