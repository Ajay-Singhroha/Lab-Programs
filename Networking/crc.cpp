#include <iostream>
#include <cstring>
#include<cstdlib>
using namespace std;
void trim(string &s);
void exor(int a[],int b[],int n,int xxor[]);                                                          // Prototypes of functions
void mod2div(int dividend[],int generator[],int size,int k,int rem[]);
int main()
{
    srand(time(NULL));
    cout<<"\n\n CYCLIC REDUNDANCY CHECK \n\n";
    int n,k;                                                                                         //  Ddclaring Variables
    string info,gen;                                                                                 //  Strings to hold inout data
    cout<<"\n\n Enter Information Bits :: ";
    cin>>info;
    trim(info);
    n=info.length();
    for(int i=0; i<n; i++)
    {
        //  Checking if string contains all
        if(info[i]!=48&&info[i]!=49)                                                               //   1s or 0s ,otherwise stop
        {
            cout<<"\n Binary Format Required !  \n  Enter \'1\' and \'0\'\n\n";
            return 0;
        }
    }
    int inform[n];
    for(int i=0; i<n; i++)                                                                              // Converting string of
        inform[i]=info[i]-48;                                                                            // information to integer array
    cout<<"\n\n Enter Generator Polynomial :: ";
    cin>>gen;
    trim(gen);
    k=gen.length();
    if(info.length()<k)
    {
        //   Checking if generator polynomial is
        cout<<"\n\n Generator Polynomial can't be greater than Information Bits !!\n\n";                    //   not greater than Information Bits
        return 0;
    }
    for(int i=0; i<k; i++)
    {
        if(gen[i]!=48&&gen[i]!=49)
        {
            //  Checking if Generator polynomial contains
            cout<<"\n Binary Format Required !  \n  Enter \'1\' and \'0\'\n\n";                             // all 1s or 0s only
            return 0;
        }
    }
    int generator[k];                                                                                   //  Converting generator string to integer array
    for(int i=0; i<k; i++)                                                                              //   generator
        generator[i]=gen[i]-48;


    int size=n+k-1;
    int dividend[size]= {0};                                                                            //   Making new Dividend array of Information + (k-1) zeroes
    for(int i=0; i<n; i++)                                                                              //  Copying info bits to dividend polynomial
        dividend[i]=inform[i];


    int rem[k-1]= {0};                                                                                  //  Making new array rem that will contain rem of modulo 2 division


    mod2div(dividend,generator,size,k,rem);                                                            //  calling fn that performs modulo 2 division
    for(int i=n; i<size; i++)
    {
        //  appending the remainder we got to last of dividend
        dividend[i]=rem[i-n];
    }
    rem[k-1]= {0};                                                                                      //  making rem all 0  for further calculation

    cout<<"\n  Sent Code Word is  :: ";
    for(int i=0; i<size; i++)                                                                              //  Displaying the sent codeword
        cout<<dividend[i];

    int  choice=0;                                                                                      //  Menu for errors introduction
    cout<<"\n\n  1. Want to introduce errors .";
    cout<<"\n\n  2. Don't Want ";
    cout<<"\n \n\n  Enter your choice :: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
    {
        int pos=rand()%size;                                                                            //  Pick a random bit and flip it
        if(dividend[pos]==0)
            dividend[pos]=1;
        else
            dividend[pos]=0;
        mod2div(dividend,generator,size,k,rem);
        int i;
        for( i=0; i<k-1&&rem[i]==0; i++) {}
        if(i<k-1)
        {
            cout<<"\n\n REMAINDER NOT ZERO \n";
            cout<<"\n Error CAUGHT!!! \n";                                                      //   if rem not all 0s then error caught .
            cout<<"\n Recieved CodeWord is :: ";
            for(int i=0; i<size; i++)
                cout<<dividend[i];                                                                //   dispaly received code word
            cout<<endl;
        }
        else
        {
            cout<<"\n Can't Caught Errors ";                                                        //  else can't caught errors
            for(int i=0; i<size; i++)
                cout<<dividend[i];
        }
        break;
    }
    case 2:
        cout<<"\n No Errors Introduced .\n";                                                       //  if no error introduced then also check by division
        mod2div(dividend,generator,size,k,rem);
        cout<<"\n\n Recieved Code Word is :: ";
        for(int i=0; i<size; i++)
            cout<<dividend[i];
        cout<<endl;
        break;
    default:
        cout<<"\n\nInvalid  Choice \n\n";
    }
    return 0;
}


void mod2div(int dividend[],int generator[],int size,int k,int rem[])                                       //   Function for %2/
{
    int temp[k] = {0};
    int xxor[k] = {0};
    int last=k;
    for(int i=0; i<k; i++)
    {
        temp[i]=dividend[i];

    }
    while(last<=size)
    {


        if(temp[0]==1)
        {
            exor(temp,generator,k,xxor);
        }
        else
        {

            for(int i=0; i<k; i++)
                xxor[i]=temp[i];
        }
        last++;
        for(int i=0; i<k-1; i++)
        {
            temp[i]=xxor[i+1];
        }
        temp[k-1]=dividend[last-1];




    }
    for(int i=0; i<k-1; i++)
        rem[i]=xxor[i+1];

}


void exor(int a[],int b[],int k,int xxor[])
{
    for(int i=0; i<k; i++)
    {
        if(a[i]==b[i])
            xxor[i]=0;
        else
            xxor[i]=1;
    }
}
void  trim(string &s)
{
    while(s[0]=='0')
    {
        s=s.substr(1);
    }
}
