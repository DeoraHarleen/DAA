#include<iostream>
using namespace std;
int main()
{
    int n=5;
    int jobs[]={1,2,3,4,5};
    int deadline[]={2,1,2,1,3};
    int profit[]={100,19,27,25,15};
    
    bool slot[n];
    for(int i=0;i<n;i++)
    {
        slot[i]=false;
    }
    
    int result[n];
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(profit[j]<profit[j+1])
            {
                swap(profit[j],profit[j+1]);
                swap(deadline[j],deadline[j+1]);
                swap(jobs[j],jobs[j+1]);
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,deadline[i])-1;j>=0;j--)
        {
            if(!slot[j])
            {
                slot[j]=true;
                result[j]=i;
                break;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(slot[i])
        {
            cout<<jobs[result[i]]<<" ";
        }
    }
    
}
