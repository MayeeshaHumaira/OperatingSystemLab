#include <bits/stdc++.h>
using namespace std;

struct head
{
    int num;
    int flag;
};

struct head h[33];
int as[33], ar[33],seq[33];
int x, n, minm, location, head, sum = 0,k=0;

int main()
{
    cout<<"Enter total number of locations: ";
    cin>>n;
    cout<<"Enter position of disk head: ";
    cin>>head;
    cout<<"Enter elements of disk head queue: ";
    for(int i=0; i<n; i++)
    {
        cin>>h[i].num;
        h[i].flag =0;
    }

    for(int i = 0; i < n; i++)
    {
        x = 0;
        minm = 0;
        location = 0;
        for(int j = 0; j < n; j++)
        {
            if(h[j].flag == 0)
            {
                if(x == 0)
                {
                    as[j] = abs(head - h[j].num);
                    minm = as[j];
                    location = j;
                    x++;
                }
                else
                {
                    as[j] = abs(head - h[j].num);
                }
                if(minm > as[j])
                {
                    minm = as[j];
                    location = j;
                }
            }
        }
        h[location].flag = 1;
        ar[i] = abs(h[location].num - head);
        head = h[location].num;
        seq[k++]=head;
    }

    cout<<"Sequence is:\n";
    for(int i=0; i<n; i++)
    {
        sum = sum + ar[i];
        cout<<seq[i]<<"\n";
    }

    cout<<"Total movements of the cylinders: "<<sum;
    return 0;
}
