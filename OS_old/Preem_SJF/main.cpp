#include <iostream>
#include <cstdlib>
using namespace std;
void input(int arr[],int n)
{

	for(int i=0; i<n; i++)
	{
		cout<<"\n   Enter for  P["<<i+1<<"]  :: ";
		cin>>arr[i];
	}
}
void calculate_WT(int WT[],int process[],int arrivalt[],int burstt[],int n)
{

	int time=0;
	int shortest=0;
	int minimum_job=INT_MAX;
	bool found=false;
	int count=0;
	int remT[n]= {0};
	for(int i=0; i<n; i++)
		remT[i]=burstt[i];
	while(count!=n)
	{
		for(int i=0; i<n; i++)
		{

			if((arrivalt[i]<=time)&&remT[i]<minimum_job&&remT[i]>0)
			{
				shortest=i;
				found=true;
			}
		}
		if(!found)
		{
			time++;
			continue;
		}
		remT[shortest]--;
		minimum_job=remT[shortest];
		if(minimum_job==0)
            minimum_job=INT_MAX;
		if(remT[shortest]==0)
		{
			count++;
			WT[shortest]=time+1-burstt[shortest]-arrivalt[shortest];
			if(WT[shortest]<0)
				WT[shortest]=0;
		}

		time++;


	}
}

void calculate_TAT(int burstt[],int n,int WT[],int TAT[])
{
	for(int i=0; i<n; i++)
	{
		TAT[i]=WT[i]+burstt[i];
	}
}

void display(int TAT[],int WT[],int process[],int n)
{

}

int main()
{
	cout<<"\n\n Process Scheduling by Preemptive SJF \n\n";
	cout<<"\n Enter no. of processes :: ";
	int n;
	cin>>n;
	int process[n]= {0};
	int arrivalt[n]= {0};
	int burstt[n]= {0};
	int TAT[n]= {0};
	int WT[n]= {0};
	int RT[n]= {0};
	cout<<"\n Processes are :: ";
	for(int i=0; i<n; i++)
	{
		process[i]=i+1;
		cout<<"  P"<<i+1;
	}

	cout<<"\n\n Enter arrival time for processes :: ";
	input(arrivalt,n);

	cout<<"\n\n Enter burst Time for Processes :: ";
	input(burstt,n);



	calculate_WT(WT,process,arrivalt,burstt,n);
	calculate_TAT(burstt,n,WT,TAT);

	cout<<"\t\t\t"<<"Processes"<<"\t\t\t"<<"TAT"<<"\t\t\t"<<"WT";
	for(int i=0; i<n; i++)
		cout<<"\n\t\t\t"<<process[i]<<"\t\t\t"<<TAT[i]<<"\t\t\t"<<WT[i];

	return 0;
}
