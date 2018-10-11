#include <iostream>
#include <iomanip>
using namespace std;
float cal_avg(int arr[],int n)
{
    int sum=0;
    for(int i=0; i<n; i++)

        sum+=arr[i];
    return (sum);
}
int   sum_burst(int burst_time[],int i)
{
    int sum=0;
    for(int j=0; j<i; j++)
    {

        sum+=burst_time[j];

    }
    return sum;
}
void  input(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"\n Enter for P"<<i+1<<" :: ";

        cin>>arr[i];
        if(arr[i]<0)
            throw arr[i];
    }
}
void   sortt(int processes[],int burst_time[],int n)            // SORT ARRAY
{
    int temp=0,temp1=0;

    for(int i=0; i<n; i++)
    {
        bool flag=false;
        for(int j=0; j<n-1; j++)
        {
            if(burst_time[j+1]<burst_time[j])
            {
                flag=true;
                temp=processes[j+1];
                processes[j+1]=processes[j];
                processes[j]=temp;

                temp1=burst_time[j+1];
                burst_time[j+1]=burst_time[j];
                burst_time[j]=temp1;
            }
        }
        if(!flag)
            return;
    }
}

void   calculate_WT_RT(int WT[],int RT[],int burst_time[],int n)
{

    for(int i=0; i<n; i++)
    {
            RT[i]=WT[i]=sum_burst(burst_time,i);
    }
}
void   calculate_TAT(int TAT[],int burst_time[],int n)
{
    for(int i=0; i<n; i++)
    {
        TAT[i]=(sum_burst(burst_time,i)+burst_time[i]);
    }
}

void  display(int processes[],int TAT[],int WT[],int RT[],int n)
{
    cout<<"\n\n  Table   ";

    cout<<"\n Processes "<<setw(4)<<"TAT"<<setw(6)<<"WT"<<setw(6)<<"RT";

    for(int i=0; i<n; i++)
    {
        cout<<"\n  "<<setw(6)<<" P"<<processes[i]<<setw(6)<<TAT[i]<<setw(6)<<WT[i]<<setw(6)<<RT[i];
    }
    cout<<"\n Average "<<setw(5)<<cal_avg(TAT,n)/n<<setw(8)<<cal_avg(WT,n)/n<<setw(6)<<cal_avg(RT,n)/n;
}

int main()
{
    int n;
    cout<<"\n Process Scheduling By Non-Preemptive SJF ";
    cout<<"\n Arrival Time assumed to be zero for all . \n";
    cout<<"\n Enter No. of Processes :: ";
    cin>>n;
    int processes[n]= {0};
    int burst_time[n]= {0};
    int TAT[n]= {0};
    int RT[n]= {0};
    int WT[n]= {0};
    cout<<"\n Processes are :: ";
    for(int i=0; i<n; i++)
    {
        processes[i]=i+1;
        cout<<"  P"<<i+1;
    }
    try
    {
        cout<<"\n\n Enter Burst Time(BT) for Processes :: ";
        input(burst_time,n);
    }
    catch(int error)
    {
        cout<<"\n Time can't be negative ! ";
        return error;
    }
    sortt(processes,burst_time,n);
    calculate_TAT(TAT,burst_time,n);
    calculate_WT_RT(WT,RT,burst_time,n);
    display(processes,TAT,WT,RT,n);
    return 0;
}

