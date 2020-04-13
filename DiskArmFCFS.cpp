#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    cout<<"Enter number of cylinder Request: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" Cylinder Request: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int head;
    cout<<"Enter Head: ";
    cin>>head;

    int seek_count = 0;
    int distance, cur_track;

    for (int i = 0; i < n; i++) {
        cur_track = arr[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    cout << "Total number of seek operations = "
         << seek_count << endl;
    cout << "Seek Sequence is" << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
