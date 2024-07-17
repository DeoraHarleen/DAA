#include <iostream>
using namespace std;
int main()
{
    
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    int x;
    cin>>x;
    
    int low=0;
    int high=n-1;
    bool found = false;
      while(low<=high)
        {
            int mid=(low+high)/2;
        
        
        if(x==arr[mid])
        {
            cout<<"Element found at "<<mid<<" "<<endl;
            found=true;
            break;
        }
        else if(x<arr[mid])
        {
            high=mid-1;
            
        }
        else 
        {
            low=mid+1;
        }
        }
        if(!found)
        {
            cout<<"Not present";
        }
    
    return 0;
}
