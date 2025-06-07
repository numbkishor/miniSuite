#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int arr[n];
    bool found= false;
    for(int i=0; i<n; i++) 
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    for(int i=0; i<n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}