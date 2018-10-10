#include <iostream>
#include <cstdint>
#include <liimts>

#include "block.h"
#include "process.h"

using namespace std;
int findFirstFit(int p_size,int blocks[],int m)
{

    for(int i=0; i<m; i++)
    {
        if(blocks[i]>=p_size)
        {
            return i;
        }
    }
    return -1;
}

void firstFit(int Copy[],int copyP[],int n,int m)
{


    for(int i=0; i<n; i++)
    {
        int j=findFirstFit(copyP[i],Copy,m);
        if(j!=-1)
        {
            Copy[j]-=copyP[i];
            copyP[i]=0;
        }
    }
}


int findBestFit(int p_size,int blocks[],int m)
{
    int best=INT_MAX;
    for(int i=0; i<m; i++)
    {
        if(blocks[i]>=p_size)
        {
            if(i<best)
                best=i;

        }
    }
    if(best!=-1)
        return best;
    return -1;
}

void bestFit(int Copy[],int copyP[],int n,int m)
{


    for(int i=0; i<n; i++)
    {
        int j=findBestFit(copyP[i],Copy,m);
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
    for(int i=0; i<m; i++)
    {
        b[i].input();
    }

    int Copy[m]= {0};

    for(int i=0; i<m; i++)
    {
        Copy[i]=b[i].getSize();
    }



    cout<<"\n\n\n Enter no. of Processes : ";
    cin>> n;
    process p[n];


    cout<<"\n\n Enter Process Details \n\n";
    for(int i=0; i<n; i++)
    {
        p[i].input();
    }

    int copyP[n]= {0};

    for(int i=0; i<n; i++)
    {
        copyP[i]=p[i].getPSize();
    }


    bestFit(Copy,copyP,n,m);



    for(int i=0; i<m; i++)
        cout<<" "<<Copy[i];


}
