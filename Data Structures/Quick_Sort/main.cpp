//  Quick Sorting Algorithm
#include <iostream>
#define MAX 30
using namespace std;
int split(int array[],int l,int h)
{
    int pivot=array[l];

    int left=l;
    int right=h;

    while(left<right)
    {
        while(array[left]<=pivot&&left<h)
            left++;
        while(array[right]>pivot)
            right++;
        if(left<right)
        {
            int temp=array[left];
            array[left]=array[right];
            array[right]=temp;
        }
    }
    array[l]=array[right];
    array[right]=pivot;
    return right;
}

void quick_sort(int array[],int l,int h)
{
    int pos;
    if(l<h)
    {
        pos=split(array,l,h);
        quick_sort(array,l,pos-1);
        quick_sort(array,pos+1,h);
    }
}
int main()
{
    int n;
    int array[MAX]= {0};
    cout << "\n\n Enter size of array :: ";
    cin>>n;

    cout<<"\n\n Enter Elements of array to be sorted :: ";
    for(int i=0; i<n; i++)
    {
        cout<<" \n  Enter for array["<<i<<"] :: ";
        cin>>array[i];
    }
    cout<<"\n After input";
    quick_sort( array,0,n-1);


    cout<<"\n\n Sorted Array is :: ";
    for(int i=0; i<n; i++)
        cout<<" "<<array[i];
    cout<<"\n\n";
    return 0;
}
