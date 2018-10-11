#include <iostream>
#include "block.h"
#include "process.h"
#include "BestFit.h"
#include "FirstFit.h"
#include "WorstFit.h"
#define MAX 50
using namespace std;
void output(int arr[],int n);



int main()
{
    FirstFit ff;
    BestFit bf;
    WorstFit wf;
    int process[MAX];
    int memory[MAX];
    int fprocess[MAX];
    int fmemory[MAX];
    
    int bprocess[MAX];
    int bmemory[MAX];
    
    int wprocess[MAX];
    int wmemory[MAX];
    int p=0,m=0;
    cout<<"\n\n Enter no. of Memory Blocks : ";
    cin>> m;
    cout<<"\n\n Enter Size of "<<m<<" memory blocks :: ";
    for(int i=0; i<m; i++)
        cin>>memory[i];

 	for(int i=0;i<m;i++)
	{
		fmemory[i]=memory[i];
	}
	for(int i=0;i<m;i++)
	{
		bmemory[i]=memory[i];
	}
	for(int i=0;i<m;i++)
	{
		wmemory[i]=memory[i];
	}




    cout<<"\n\n\n Enter no. of Processes : ";
    cin>> p;



    cout<<"\n\n Enter Size of "<<p<<" processes :: ";
    for(int i=0; i<p; i++)
        cin>>process[i];

 	for(int i=0;i<p;i++)
	{
		bprocess[i]=process[i];
	}
	for(int i=0;i<p;i++)
	{
		wprocess[i]=process[i];
	}
	for(int i=0;i<p;i++)
	{
		fprocess[i]=process[i];
	}

   
       // ff.firstfit(fprocess,fmemory,p,m);
  
	bf.bestfit(bprocess,bmemory,p,m);

        
       
      	//wf.worstfit(wprocess,wmemory,p,m);

    	//output(fprocess,p);
    	//output(fmemory,m);
    	
    	
    	
    	//output(bprocess,p);
    	output(bmemory,m);
	cout<<"\n\n\n";
	for(int i=0;i<p;i++)
		cout<<"   "<<bprocess[i];
		cout<<"\n\n\n";
		
	//	for(int i=0;i<m;i++)
	//cout<<"   "<<bmemory[i];

}

void output(int arr[],int n)
{
	cout<<"\n\n\n";
	for(int i=0;i<n;i++)
		cout<<"   "<<arr[i];
}
void copy(int original[],int copy[],int size)

{
	for(int i=0;i<size;i++)
	{
		copy[i]=original[i];
	}
}

