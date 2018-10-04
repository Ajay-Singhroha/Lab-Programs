#include<iostream>
using namespace std;
class Process
{
private:
    string pid;
    int burst_time;
    int arrival_time;
    int priority;
    int TAT;
    int WT;
    int RT;
    int endTime;
public:
    Process()
    {
        pid="";
        burst_time=priority=-1;
        TAT=WT=RT=endTime=-1;
        arrival_time=0;
    }
    void input()
    {
        cout<<endl<<endl;
        cout<<"\n\n Enter process id :: ";
        cin >> pid;
        cout<<"\n\n Enter Burst Time of Process "<<pid<<" :: ";
        cin>>burst_time;
        cout<<"\n\n Enter Arrival Time of Process "<<pid<<" :: ";
        cin>>arrival_time;
    }
    void inputWithPriority()
    {
        cout<<"\n\n Enter process id :: ";
        cin >> pid;
        cout<<"\n\n Enter Burst Time of Process "<<pid<<" :: ";
        cin>>burst_time;
        cout<<"\n\n Enter Arrival Time of Process "<<pid<<" :: ";
        cin>>arrival_time;
        cout<<"\n\n Enter Priority of Process "<<pid<<" :: ";
        cin>>priority;
    }
    void display()
    {
        cout<<"\n\t Process "<<pid<<" \t "<<burst_time<<" \t\t "<<arrival_time<<" \t "<<TAT<<" \t "<<WT<<" \t "<<RT;
    }


    string getPid()
    {
        return pid;
    }
    int getArrivalTime()
    {
        return arrival_time;
    }
    int getBurstTime()
    {
        return burst_time;
    }
    int getPriority()
    {
        return priority;
    }
    int getTAT()
    {
        return TAT;
    }
    int getWT()
    {
        return WT;
    }
     int getRT()
    {
        return RT;
    }
      int getEndTime()
    {
        return endTime;
    }
    void setBurstTime(int value)
    {
        burst_time=value;
        if(burst_time<0)
            burst_time=0;
    }
    void setTAT(int value)
    {
        TAT=value;
        if(TAT<0)
            TAT=0;
    }
    void setWT(int value)
    {
        WT=value;
        if(WT<0)
            WT=0;
    }
     void setPriority(int value)
    {
        priority=value;

    }
    void setRT(int value)
    {
        RT=value;
        if(RT<0)
            RT=0;
    }
    void setEndTime(int value)
    {
        endTime=value;
        if(endTime<0)
            endTime=0;
    }
};
