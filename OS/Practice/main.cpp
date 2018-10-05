#include <iostream>
#include "block.h"
#include "process.h"

using namespace std;
int findFirstFit(int p_size,int blocks[])
{

    for(int i=0;i<(sizeof(blocks)/sizeof(blocks[0]));i++)
    {
        if(blocks[i]>=p_size)
        {
            return i;
        }
    }
    return -1;
}

void firstFit(int Copy[],int copyP[])
{
    cout<<(sizeof(copyP)/sizeof(copyP[1]));

    for(int i=0;i<3;i++)
    {
        int j=findFirstFit(copyP[i],Copy);
        if(j!=-1)
        {
            Copy[j]-=copyP[i];
            copyP[i]=0;
        }
    }
}




int main()
{
    int n=0,m=0;
    cout<<"\n\n Enter no. of Memory Blocks : ";
    cin>> m;
    block b[m];


    cout<<"\n\n Enter Block Details \n\n";
    for(int i=0;i<m;i++)
    {
        b[i].input();
    }

    int Copy[m]={0};

    for(int i=0;i<m;i++)
    {
        Copy[i]=b[i].getSize();
    }



    cout<<"\n\n\n Enter no. of Processes : ";
    cin>> n;
    process p[n];


    cout<<"\n\n Enter Process Details \n\n";
    for(int i=0;i<n;i++)
    {
       p[i].input();
    }

    int copyP[n]={0};

    for(int i=0;i<n;i++)
    {
        copyP[i]=p[i].getPSize();
    }


    firstFit(Copy,copyP);


        for(int i=0;i<n;i++)
        cout<<" "<<copyP[i];
        for(int i=0;i<m;i++)
        cout<<" "<<Copy[i];


}
