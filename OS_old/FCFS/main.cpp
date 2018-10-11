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




    void inp();
    void sortt();
    void calculate_TAT();
    void calculate_WT();
    void display();
    int sum_TAT(int n);


    n=s;
    processes[n]= {0};
    burst_time[n]= {0};
    arrival_time[n]= {0};
    TAT[n]= {0};
    RT[n]= {0};
    WT[n]= {0};
    cout<<"\n Processes are :: ";
    for(int i=0; i<n; i++)
    {
        processes[i]=i+1;
        cout<<"  P"<<i+1;
    }
}
void FCFS:: inp()
{

    cout<<"\n\n Enter Burst Time(BT) for Processes :: ";
    for(int i=0; i<n; i++)
    {
        cout<<"\n Enter for P"<<i+1<<" :: ";

        cin>>burst_time[i];
    }

    cout<<"\n\n Enter Arrival_Time(AT) for Processes :: ";
    for(int i=0; i<n; i++)
    {
        cout<<"\n Enter for P"<<i+1<<" :: ";

        cin>>arrival_time[i];
    }
}

void  FCFS:: sortt()            // SORT ARRAY
{
    int temp=0,hold=0,temp1;

    for(int i=0; i<n; i++)
    {
        bool flag=false;
        for(int j=0; j<n-1; j++)
        {
            if(arrival_time[j+1]<=arrival_time[j])
            {
                flag=true;
                temp=processes[j+1];
                processes[j+1]=processes[j];
                processes[j]=temp;

                hold=arrival_time[j+1];
                arrival_time[j+1]=arrival_time[j];
                arrival_time[j]=hold;

                temp1=burst_time[j+1];
                burst_time[j+1]=burst_time[j];
                burst_time[j]=temp1;

            }
        }
        if(!flag)
            return;
    }

}

void  FCFS:: calculate_WT()
{
    int free_time=arrival_time[0]-0;
    for(int i=0; i<n; i++)
    {
        if(arrival_time[i]==free_time)
            WT[i]=RT[i]=0;

        if(arrival_time[i]==(sum_TAT(i)+free_time))
            WT[i]=RT[i]=0;

        else
            RT[i]=WT[i]=sum_TAT(i)+free_time-arrival_time[i];
    }
}


void  FCFS:: calculate_TAT()
{
    int free_time=0;
    free_time=arrival_time[0]-0;
    for(int i=0; i<n; i++)
    {


        if(i==0)
            TAT[i]=(burst_time[i]+arrival_time[i]-free_time);
        else
        {
            TAT[i]=(sum_TAT(i)+free_time+burst_time[i])-(arrival_time[i]);
        }

    }
}
int  FCFS:: sum_TAT(int i)
{
    int sum=0;
    for(int j=0; j<i; j++)
    {

        sum+=burst_time[j];

    }
    return sum;
}
void FCFS:: display()
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
    cout<<"\n Process Scheduling By Non-Preemptive FCFS ";
    cout<<"\n Enter No. of Processes :: ";
    cin>>n;
    int n;
    int processes[n];
    int burst_time[n];
    int arrival_time[n];
    int TAT[n];
    int RT[n],WT[n];


    f1.inp();
    f1.sortt();
    f1.calculate_TAT();
    f1.calculate_WT();
    f1.display();





    return 0;
}


