#include<iostream>
#include "Process.cpp"
using namespace std;

void calculate(Process p[],int n,double &TAT,double &WT,double &RT)            // Calculate Average of TAT,WT,RT
{
    for(int i=0; i<n; i++)
    {
        TAT+=p[i].getTAT();
        WT+=p[i].getWT();
        RT+=p[i].getRT();
    }

    TAT/=n;
    WT/=n;
    RT/=n;
}
bool pidAvailable(Process p[],int i)                                         // Check if P_id is available or not
{
    // for Current process
    for(int j=0; j<i; j++)                                                   //  Process Ids should be unique
    {
        if(p[j].getPid()==p[i].getPid())
            return false;
    }
    return true;
}
bool validData(Process p[],int i)                                            //  Check for wrong burst and
{
    //  arrival time

    if(p[i].getBurstTime()<=0||p[i].getArrivalTime()<0)
        return false;
    else
        return true;
}

void sort(Process p[],int n)                                                // sort Process Array according to
{
    // arrival time and burst Time
    for(int i=0; i<n; i++)
    {
        bool flag=false;
        for(int j=0; j<n-1; j++)
        {
            if(p[j].getBurstTime()>p[j+1].getBurstTime())
            {
                flag=true;
                Process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
        if(!flag)
            break;
    }
}
void sortt(Process p[],int n)                                                // sort Process Array according to
{
    // arrival time and burst Time
    for(int i=0; i<n; i++)
    {
        bool flag=false;
        for(int j=0; j<n-1; j++)
        {
            if(p[j+1].getArrivalTime()<p[j].getArrivalTime())
            {
                flag=true;
                Process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
            if(p[j+1].getArrivalTime()==p[j].getArrivalTime()&&p[j+1].getBurstTime()<p[j].getBurstTime())
            {
                flag=true;
                Process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
        if(!flag)
            break;
    }
}

int sumTillI(Process p[],int i)                                              // Sum of burst_time's till  process i
{
    int sum=0;
    for(int j=0; j<=i; j++)
        sum+=p[j].getBurstTime();
    return sum;
}

void calculate_TAT(Process p[],int n)                                        // Calculate TAT of processes
{
    int idle_time=p[0].getArrivalTime()-0;                                  // Calculate Idle Time of CPU
    // In Case, When Arrival Time is not zero for any process.
    for(int i=0; i<n; i++)
    {
        p[i].setTAT(sumTillI(p,i));
        if(i==0)
            p[i].setTAT(p[i].getTAT()+idle_time-p[i].getArrivalTime());
        if(i!=0&&p[i].getArrivalTime()-p[i-1].getTAT()-idle_time>0)
            idle_time=p[i].getArrivalTime()-p[i-1].getTAT();
        if(i!=0)
            p[i].setTAT(p[i].getTAT()+idle_time-p[i].getArrivalTime());
    }
}
void calculate_WT_RT(Process p[],int n)                                     // Calculate WT  and RT of processes
{
    for(int i=0; i<n; i++)
    {
        p[i].setWT(p[i].getTAT()-p[i].getBurstTime());
        p[i].setRT(p[i].getWT());
    }
}

int main()
{
    int n;
    double TAT=0,WT=0,RT=0;
    int choice;
    cout<<"\n\n SJF Scheduling Algorithm \n";
    cout<<"\n\n Enter No. of Processes :: ";
    cin >>n;
    Process p[n];                                                         //  Define Array of Processes


    cout<<"\n\n MENU   \n ";
    cout<<"\n\n 1. With Same Arrival Time .";
    cout<<"\n\n 2. With Different Arrival Time .";
    cout<<"\n\n\n Enter your choice :: ";
    cin>>choice ;
    switch(choice)
    {
    case 1:

        for(int i=0; i<n; i++)
        {
            p[i].inputWithoutArrivalTime();                                // Take input without Arrival Time
            if(!pidAvailable(p,i))
            {
                cout<<"\n\n Process already in CPU \n\n Enter new process :: ";
                i--;
                continue;
            }
            if(!validData(p,i))
            {
                cout<<"\n\n Invalid Data ! \n\n";
                i--;
                continue;
            }
        }
        break;
    case 2:
    {
        for(int i=0; i<n; i++)
        {
            p[i].input();                                                       // Take input  with Arrival Time
            if(!pidAvailable(p,i))
            {
                cout<<"\n\n Process already in CPU \n\n Enter new process :: ";
                i--;
                continue;
            }
            if(!validData(p,i))
            {
                cout<<"\n\n Invalid Data !! \n\n";
                i--;
                continue;
            }
        }

    }
    break;

    default:
        cout<<"\n\n Wrong CHOICE !";
    }
    sortt(p,n);
    calculate_TAT(p,n);
    calculate_WT_RT(p,n);
    cout<<"\n\t Processes   burst_time  arrival_time    TAT  \t WT  \t RT \n";

    for(int i=0; i<n; i++)
        p[i].display();
    calculate(p,n,TAT,WT,RT);
    cout<<"\n\n\t Average \t\t\t\t "<<TAT<<"  \t "<<WT<<"  \t "<<RT<<" \n\n";
    cout<<"\n\n";


    return 0;
}
