#include<iostream>
#include "Process.cpp"
using namespace std;
void display(Process p[],int n)
{


}
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
    // arrival time
    for(int i=0; i<n; i++)
    {
        bool flag=false;
        for(int j=0; j<n-1; j++)
        {
            if(p[j].getArrivalTime()>p[j+1].getArrivalTime())
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
    int cpu_time=0;
    int burst[n]= {0};
    for(int i=0; i<n; i++)
        burst[i]=p[i].getBurstTime();

    int count=0;
    bool p_found;
    int current=0;
    while(count!=n)
    {

        //Select the process that is ready to run

        p_found=false;                                                            // This loop is selecting the process
        for(int i=0; i<n; i++)                                                   // with shortest burst time remaining at
        {
            if((burst[i]>0&&p[i].getArrivalTime()<=cpu_time))               // some cpu_time
            {
                p_found=true;
                current=i;
                break;
            }
        }

        if(!p_found)                                                        // if there is no process then continue
        {
            // to next cpu cycle (cpu is idle)
            cpu_time++;
            continue;
        }

        if(p[current].getRT()==-1)                                          // if process is entererd first time
        {
            //  set its response time
            p[current].setRT(cpu_time-p[current].getArrivalTime());
        }



        // Decrement burst time for process
        cpu_time+=burst[current];
        burst[current]=0;                                                         // increment cpu cycle



        if(burst[current]==0)                                               // if any process is completed
        {
            // set its tat
            count++;
            p[current].setEndTime(cpu_time);                                                 // increment count (no of process completed)
            p[current].setTAT(cpu_time-p[current].getArrivalTime());
        }

    }
}
void calculate_WT(Process p[],int n)                                     // Calculate WT  and RT of processes
{
    for(int i=0; i<n; i++)
    {
        p[i].setWT(p[i].getTAT()-p[i].getBurstTime());
    }
}

int main()
{
    int n;
    double TAT=0,WT=0,RT=0;
    int choice;
    cout<<"\n\n FCFS Scheduling Algorithm \n";
    cout<<"\n\n Enter No. of Processes :: ";
    cin >>n;
    Process p[n];                                                         //  Define Array of Processes


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




    sort(p,n);

    calculate_TAT(p,n);


    calculate_WT(p,n);

    cout<<"\n\n Gantt Chart ::";
    void display(p,n);
    cout<<"\n\t Processes   burst_time  arrival_time    TAT  \t WT  \t RT \n";

    for(int i=0; i<n; i++)
        p[i].display();
    calculate(p,n,TAT,WT,RT);
    cout<<"\n\n\t Average \t\t\t\t "<<TAT<<"  \t "<<WT<<"  \t "<<RT<<" \n\n";
    cout<<"\n\n";


    return 0;
}
