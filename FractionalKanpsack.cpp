#include<iostream>
#include<algorithm>
using namespace std;

double fractionalKnapsack(int n, int weight[], int profit[], int capacity)
{
    double ratios[n];
    for(int i=0;i<n;i++)
    {
        ratios[i]=(double)profit[i]/weight[i];
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ratios[i]<ratios[j])
            {
                swap(ratios[i],ratios[j]);
                swap(weight[i],weight[j]);
                swap(profit[i],profit[j]);
            }
        }
    }
    
    int maxProfit=0;
    for(int i=0;i<n;i++)
    {
        if(weight[i]<=capacity)
        {
            maxProfit=maxProfit+profit[i];
            capacity=capacity-weight[i];
        }
        else
        {
            maxProfit=maxProfit+ratios[i]*capacity;
            capacity=0;
        }
    }
    return maxProfit;
}

int main()
{
    int weight[]={10,20,30};
    int profit[]={60,100,120};
    double n=sizeof(weight)/sizeof(weight[0]);
    int capacity=50;
    double result=fractionalKnapsack(n,weight,profit,capacity);
    cout<<result;
}
