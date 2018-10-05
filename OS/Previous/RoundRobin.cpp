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


int ifProcessIsLast(int burst[],int n)
{
    int count=0;
    int i=0;
    for(; i<n; i++)
    {
        if(burst[i]!=0)
            count++;
    }

    if(count==1)
        return --i;
    else
        return -1;

}

void calculate_TAT(Process p[],int n,int time,string s)                                        // Calculate TAT of processes
{
    int burst[n]= {0};
    for(int i=0; i<n; i++)
        burst[i]=p[i].getBurstTime();
    int cpu_time=p[0].getArrivalTime();
    int count=0;
    int current=0,previous=-1;
    bool p_found=false;
    while(count!=n)
    {
        int i=0;
        //Select the process that is ready to run
        for(; i<n; i++)
        {
            if((burst[i]>0&&p[i].getArrivalTime()<=cpu_time)&&(i!=previous))
            {
                if(p[i].getRT()==-1)
                    p[i].setRT(cpu_time-p[i].getArrivalTime());
                current=i;
                s+=p[i].getPid();
                p_found=true;
                break;
            }
        }
        if(ifProcessIsLast(burst,n)!=-1)
        {
            current=ifProcessIsLast(burst,n);

            cpu_time+=burst[current];
            p[current].setTAT(cpu_time-p[current].getArrivalTime());
            cout<<cpu_time;
            break;
        }
        if(!p_found)
        {
            cpu_time++;
            continue;
        }
        if(burst[current]<time)
        {
            cpu_time+=burst[current];
            burst[current]=0;
        }
        else
        {
            cpu_time+=time;

            burst[current]-=time;
        }
        previous=current;

        if(burst[current]==0)
        {
            count++;
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
    int n,time;
    double TAT=0,WT=0,RT=0;
    int choice;
    string s="";
    cout<<"\n\n RoundRobin Scheduling Algorithm \n";
    cout<<"\n\n Enter No. of Processes :: ";
    cin >>n;
    Process p[n];                                                         //  Define Array of Processes
    cout<<"\n\n Enter time slice :: ";
    cin>>time;
    cout<<"\n\n Enter Information of processes : \n\n";
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

    calculate_TAT(p,n,time,s);

    calculate_WT(p,n);
    cout<<s;
    cout<<"\n\t Processes   burst_time  arrival_time    TAT  \t WT  \t RT \n";

    for(int i=0; i<n; i++)
        p[i].display();
    calculate(p,n,TAT,WT,RT);
    cout<<"\n\n\t Average \t\t\t\t "<<TAT<<"  \t "<<WT<<"  \t "<<RT<<" \n\n";
    cout<<"\n\n";


    return 0;
}
