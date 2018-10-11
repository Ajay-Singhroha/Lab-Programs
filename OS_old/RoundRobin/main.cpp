#include <iostream>

using namespace std;



class RoundRobin
{
private:
    int number;
    int process_id;
    int arrival_time;
    int burst_time;
    int tat;
    int waiting_time;
    int response_time;
public:
    RoundRobin()
    {
        number=0;
        process_id=arrival_time=burst_time=-1;
        tat=waiting_time=response_time=-1;
    }
    RoundRobin(int n)
    {
        number=n;
    }
    RoundRobin(int pid,int ar,int bt)
    {
        process_id=pid;
        arrival_time=ar;
        burst_time=bt;
    }
    void input()
    {
        cout<<"\n\n Enter Process id (Int Value ) :: ";
        cin>>process_id;
        cout<<"\n\n Enter Arrival Time of Process "<<process_id<<" :: ";
        cin>>arrival_time;
        cout<<"\n\n Enter Burst Time of Process "<<process_id<<" :: ";
        cin>>burst_time;
    }

    int getArrivalTime()
    {
        return arrival_time;
    }
    int getBurst()
    {
        return burst_time;

    }
    int getpid()
    {
        return process_id;
    }
    int getNumber()
    {
        return number;
    }
    int getWaiting()
    {
        return waiting_time;
    }
    int getResponse()
    {
        return response_time;
    }
    void setNumber(int num)
    {
        number=num;
    }
    void setWaiting(int value)
    {
        waiting_time=value;
    }
    void setResponse(int value)
    {
        response_time=value;
    }
    void setBurst(int value)
    {
        burst_time=value;
    }
    void display()
    {
        cout<<"\t "<<process_id<<"\t"<<burst_time<<"\t"<<arrival_time;
    }
};

void computeWaiting(RoundRobin r[],int n,int time);


int main()
{
    cout<<"\n\n Round Robin Scheduling Algorithm .";

    int n,time;

    cout<<"\n\n Enter no. of processes :: ";
    cin>>n;

    cout<<"\n\n Enter Time Slice :: ";
    cin>>time;

    RoundRobin r[n];

    cout<<"\n\n Enter Processes' Information :: ";
    for(int i=0; i<n; i++)
    {
        r[i].input();
        r[i].setNumber(i+1);
    }


    computeWaiting(r,n,time);


    cout<<"\n\n Waiting time of all processes ";
    for(int i=0; i<n; i++)
    {
        cout<<" "<<r[i].getWaiting();
    }
    return 0;
}

void computeWaiting(RoundRobin r[],int n,int time)
{
    int cpu_time=0;
    int cpu=-1;
    bool p_found;
    int count=0;
    int i=-1;

    while(count!=n)
    {
        p_found=false;

        for(i=0; i<n; i++)
        {
            cout<<"here i m";
            if(r[i].getArrivalTime()<=cpu_time&&r[i].getBurst()>0)
            {
                if(cpu!=i)
                {
                    cpu=r[i].getpid();
                    r[i].setNumber(r[i].getNumber()+n);
                    //  r[i].setNumber();

                    if(r[i].getResponse()==-1)
                        r[i].setResponse(cpu_time-r[i].getArrivalTime());
                    p_found=true;
                    break;

                    cout<<"\n\n inside for ";
                }
            }

        }
      //  cout<<"\n now i  m here ";
        if(!p_found)
        {
            cpu_time++;
            continue;

        }
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                if(r[j].getArrivalTime()<=cpu_time&&r[j].getBurst()>0)
                    r[j].setWaiting(r[j].getWaiting()+time);
            }
        }


        r[i].setBurst(r[i].getBurst()-time);

        if(r[i].getBurst()==0)
        {
            count++;
        }
        cpu_time+=time;

    }

}
