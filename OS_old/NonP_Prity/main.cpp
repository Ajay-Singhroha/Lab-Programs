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
void sortt(int processes[],int priority[],int burst_time[],int max_p,int n)            // SORT ARRAY
{
    int temp=0,hold=0,temp1;

    for(int i=0; i<n; i++)
    {
        bool flag=false;
        for(int j=0; j<n-1; j++)
        {
            if(priority[j+1]<=priority[j])
            {
                flag=true;
                temp=processes[j+1];
                processes[j+1]=processes[j];
                processes[j]=temp;

                hold=arrival_time[j+1];
                priority[j+1]=priority[j];
                priority[j]=hold;

                temp1=burst_time[j+1];
                burst_time[j+1]=burst_time[j];
                burst_time[j]=temp1;

            }
        }
        if(!flag)
            return;
    }

}
int sum_TAT(int burst_time[],int i)
{
    int sum=0;
    for(int j=0; j<i; j++)
    {

        sum+=burst_time[j];

    }
    return sum;
}
void calculate_WT(int WT[],int RT[],int burst_time[],int priority[],int n)
{
    int free_time=priority[0]-0;
    for(int i=0; i<n; i++)
    {
        if(priority[i]==free_time)
            WT[i]=RT[i]=0;

        if(priority[i]==(sum_TAT(burst_time,i)+free_time))
            WT[i]=RT[i]=0;

        else
            RT[i]=WT[i]=sum_TAT(burst_time,i)+free_time-priority[i];
    }
}

void calculate_TAT(int arrival_time[],int burst_time[],int n,int TAT[])
{
    int free_time=0;
    free_time=priority[0]-0;
    for(int i=0; i<n; i++)
    {


        if(i==0)
            TAT[i]=(burst_time[i]+free_time);
        else
        {
            TAT[i]=(sum_TAT(burst_time,i)+free_time+burst_time[i])
        }

    }
}
int main()
{
    cout<<"\n Process Scheduling By Non-Preemptive Priority ";
    int n;
    int max_p;
    cout<<"\n Enter Number of Processes :: ";
    cin>>n;
    int burst_time[n]= {0};
    int priority[n]= {0};
    int processes[n]= {0};
    int TAT[n]= {0};
    int WT[n]= {0};
    int RT[n]= {0};
    cout<<"\n Processes are :: ";
    for(int i=0; i<n; i++)
    {
        processes[i]=i+1;
        cout<<"  P"<<i+1;
    }
    cout<<"\n\n Enter Burst Time(BT) for Processes :: ";
    for(int i=0; i<n; i++)
    {
        cout<<"\n Enter for P"<<i+1<<" :: ";

        cin>>burst_time[i];
    }
    cout<<"\n\n Enter Maximum Priority : ";
    cin>>max_p;
    cout<<"\n\n Enter Priority for Processes :: ";
    for(int i=0; i<n; i++)
    {
        cout<<"\n Enter for P"<<i+1<<" :: ";

        cin>>priority[i];
    }
    sortt(processes,priority,burst_time,max_p,n);
    calculate_TAT(priority,burst_time,n,TAT);
    calculate_WT(WT,RT,burst_time,priority,n);
    cout<<"\n\n  Table   ";
    cout<<"\n Processes "<<setw(4)<<"TAT"<<setw(6)<<"WT"<<setw(6)<<"RT";
    for(int i=0; i<n; i++)
    {
        cout<<"\n  "<<setw(6)<<" P"<<processes[i]<<setw(6)<<TAT[i]<<setw(6)<<WT[i]<<setw(6)<<RT[i];
    }
    cout<<"\n Average "<<setw(5)<<cal_avg(TAT,n)/n<<setw(8)<<cal_avg(WT,n)/n<<setw(6)<<cal_avg(RT,n)/n;
    return 0;
}

