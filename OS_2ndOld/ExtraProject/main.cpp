#include<iostream>
#include "Process.cpp"
#include <limits.h>
#include<stdint.h>
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

int tellShortest(int smallest[],int arr_count)
{
    int shortest=0;

    for(int i=1; i<arr_count; i++)
    {
        if(smallest[i]<smallest[shortest])
            shortest=i;

    }
    return shortest;
}
void calculate_TAT(Process p[],int n)                                        // Calculate TAT of processes
{
    int burst[n]= {0};

    int arr_count=0;
    for(int i=0; i<n; i++)
        burst[i]=p[i].getBurstTime();

    int cpu_time=0;
    int count=0;
    int current=0;

    while(count!=n)
    {

        //Select the process that is ready to run
        int i=0;
        int smallest[n]= {INT_MAX};
        arr_count=0;
        for( ; i<n; i++)
        {
            if((burst[i]>0&&p[i].getArrivalTime()<=cpu_time))
            {
                smallest[i]=burst[i];
                arr_count++;
                 current=i;
            }
        }
       // cout<<"\n "<<arr_count;
        if(arr_count>1)
        {
            current=tellShortest(smallest,arr_count);

        }

        else if(arr_count==0)
        {
            cpu_time++;
            continue;
        }
 //cout<<current;

        if(p[current].getRT()==-1)
        {
            p[current].setRT(cpu_time-p[current].getArrivalTime());
        }



        burst[current]--;
        cpu_time++;



        if(burst[current]==0)
        {
            count++;
            p[current].setTAT(cpu_time-p[current].getArrivalTime());
        }

    }
}
void calculate_WT_RT(Process p[],int n)                                     // Calculate WT  and RT of processes
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
    cout<<"\n\n Preemptive SJF Scheduling Algorithm \n";
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
    for(int i=0; i<n; i++)
        p[i].display();
    /*
     calculate_WT_RT(p,n);
     cout<<"\n\t Processes   burst_time  arrival_time    TAT  \t WT  \t RT \n";

     for(int i=0; i<n; i++)
         p[i].display();
     calculate(p,n,TAT,WT,RT);
     cout<<"\n\n\t Average \t\t\t\t "<<TAT<<"  \t "<<WT<<"  \t "<<RT<<" \n\n";
     cout<<"\n\n";*/


    return 0;
}
