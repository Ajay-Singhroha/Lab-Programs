#include <iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<cstdlib>
#define MAX 50
#include<string>
using namespace std;
int parity_check(int codeword[],int size,int i);                                                    // check parity of check bits

int ret_k(int arr[],int n);                                                                         // give the value of check bits required

int main()
{
	srand(time(NULL));

	cout<<"\n\n HAMMING CODE  (assuming even parity )\n";
	int n,k;
	string s;                                                                                       //  take input in string
	int array[MAX];
	cout<<"\n\n\n Enter Information Bits:: ";
	cin>>s;

	n=s.length();
	for(int i=0; i<n; i++)
	{
		if(s[i]!=48&&s[i]!=49)                                                                      //  check if valid
		{
			cout<<"\n Error ! , Not in Binary .";
			return 0;
		}
	}

	for(int i=0; i<n; i++)
	{
		array[i]=s[i]-48;                                                                            // convert string to int array
	}



	k=ret_k(array,n);                                                                                 // get the no. of check bits in k

	int size=n+k+1;

	int codeword[size]= {0};                                                                        //  make codeword array of size (information + check bits)



	int count=0;
	for(int i=1; i<size; i=pow(2,count))
	{
		codeword[i]=-1;                                                                              //  put -1  at the place of check bits
		count++;

	}

	count=0;
	for(int i=1; i<size; i++)
	{
		if(codeword[i]!=-1)
		{                                                                                              //  map information bits to codeword
			codeword[i]=array[count];                                                                  //  where there are no check bits
			count++;
		}

	}

	for(int i=1; i<size; i++)
	{
		if(codeword[i]==-1)
		{
			int parity=parity_check(codeword,size,i);
			codeword[i]=parity;                                                                 //  calculate parity of every check bit and add it to codeword
		}
	}


	cout<<"\n\n\n  CHECK BITS APPENDED \n";                                                               // Prompt user that codeword sent
	cout<<"\n\n  Sent Codeword is :: ";
	for(int i=1; i<size; i++)
		cout<<"  "<<codeword[i];



	int choice;
	cout<<"\n\n 1. Want to introduce errors ?? ";                                                          //  ask teacher for introducong errors
	cout<<"\n\n 2. Or don't want ??";
	cout<<"\n\n  Enter your choice :: ";
	cin>>choice;
	if(choice==1)
	{                                                                                                       //  if teacher said yes
		int r=(rand()%(size+1));
        if(r==0)
             r++;                                                                                           // introduce error at some random position
		if(codeword[r]==1)
			codeword[r]=0;
		else
			codeword[r]=1;

		int errorbits=0;
		count=0;
		for(int i=1; i<size; i++)
		{
			if(i==pow(2,count))                                                                             //  again check parity of all check bits
			{
				int party=parity_check(codeword,size,i);                                                    //  if parity is incorrect ,
				if(party!=codeword[i])
					errorbits+=i;                                                                           // then error detected at that position
				count++;
			}

		}
		cout<<"\n\n Error Introduced ..";
		cout<<"\n\n REceived Codeword is :: ";                                                              //  give reciever the codeword
		for(int i=1; i<size; i++)
			cout<<"  "<<codeword[i];
		cout<<"\n\n Error at bit position \""<<errorbits<<"\" ! .";                                         //  give the position at which error ocurred
		cout<<"\n\n Corrected Code word is :: ";
		if(codeword[errorbits]==1)
			codeword[errorbits]=0;                                                                          //  correct that one bit error
		else
			codeword[errorbits]=1;

		for(int i=1; i<size; i++)
			cout<<"  "<<codeword[i];
			cout<<endl<<endl;                                                                               // give the final codeword

	}

	else
	{
		cout<<"\n\n No Errors introduced .";
		cout<<"\n\n Transmission Successfull !\n\n";
	}


	return 0;
}
int ret_k(int array[],int n)
{
	int k=0;
	for(int i=0; i<n; i++)
	{
		if(n+i+1<=pow(2,i))
		{
			k=i;
			break;
		}
	}
	return k;
}

int parity_check(int codeword[],int size,int i)
{                                                                                              // here what i m doing is ,check only those check bits in which that pariy bit
	int count=0,check=0,uncheck=0;                                                              //   "i" sent by main is a factor in addition
	for(int j=i; j<size; j++)
	{
		if(uncheck==i)                                                                          //      leave those bits that dont have "i" as a factor
		{
			check=0;
			uncheck=0;
		}
		if(check==i)                                                                            //      if as many as "i" bits are checked ,then leave next "i" bits
			uncheck++;


		if(check<i&&i!=j)                                                                        //   leave the first "i" bit itself ,bcoz that is empty
		{
			if(codeword[j]==1)
				count++;
			check++;
		}
		if(check<i&&i==j)
		{
			check++;
		}
	}
	return count%2;                                                                              //   return ,"0" or "1" as the parity .

}

