#include<iostream>
using namespace std;
# define MAX 30
class TriDiagonal
{
	private:
		int arr[MAX];
		int size;
	public:
		TriDiagonal(int s)
		{
			size=s+2*(s-1);
			int i=0;
			while(i<size)
			{	arr[i]=0;
				i++;
			}
			
			for(int i=0;i<size;i++)
				cout<<" "<<arr[i];
		}
		void set(int i,int j,int value)
		{
			switch(i-j)
			{
				case 1: arr[i-2]=value;
					break;
				case 0: arr[size+i-2]=value;
					break;
				case -1:  arr[2*size+i-2]=value;
					break;
			}
				
		}
		int get(int i,int j)
		{
			switch(i-j)
			{
				case 1:return arr[i-2];
					break;
				case 0:return arr[size+i-2];
					break;
				case -1: return arr[2*size+i-2];
					break;
				default: return 0;
			}
		}
};
int main()
{	int s=0,value=0,i=0,j=0,choice=0;
	cout<<"\n Enter Size of Matrix :: ";
	cin>>s;
	TriDiagonal d(s);
	do
	{
		cout<<"\n\n   Menu   ";
		cout<<"\n\n  1. Set Values .";
		cout<<"\n\n  2. Get Values .";
		cout<<"\n\n  3. Display .";
		cout<<"\n\n  4. Exit . ";
		cout<<"\n\n\n Enter Your Choice :: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\n Enter Values for Lower Diagonal :: ";
				
				for(int i=2;i<=s;i++)
				{
					for(int j=i-1;j<i;j++)
						{
							cout<<"\n Enter for A["<<i<<"]["<<j<<"] :: ";
							cin>>value;
							d.set(i,j,value);
						}
				}
				cout<<"\n Enter Values for Upper Diagonal :: ";
				
				for(int i=1;i<s;i++)
				{
					for(int j=i+1;j<i+2;j++)
						{
							cout<<"\n Enter for A["<<i<<"]["<<j<<"] :: ";
							cin>>value;
							d.set(i,j,value);
						}
				}
				cout<<"\n Enter Values for Main Diagonal :: ";
				
				for(int i=1;i<=s;i++)
				{
					cout<<"\n Enter for A["<<i<<"]["<<i<<"] :: ";
					cin>>value;
					d.set(i,i,value);		
				}
				break;
			case 2: cout<<"\n Enter Index Values : ";
				try
				{
				
					cout<<"\n Index Value of i :: ";
					cin>>i;
					cout<<"\n Index Value of j :: ";
					cin>>j;
					if((i>s||j>s)||(i<=0||j<=0))
						throw i;
					else
					{
							cout<<"\n Value ::"<<d.get(i,j);
						
					}
				}
				
				catch(int error)
				{
					cout<<"\n Error ,Wrong Index Value ! ";
					return 0;
				}
				
				break;
			case 3:cout<<"\n";
				for(int i=1;i<=s;i++)
				{
					for(int j=1;j<=s;j++)
					{
						if(i==j||i==j-1||i==j+1)
							cout<<""<<d.get(i,j)<<" ";
						else
							cout<<""<<0<<" ";
					}
					cout<<endl;
				}	
				break;
			case 4: return 0;
				break;
			default : cout<<"\n WRONG CHOICE ";
		}
	}while(choice<4);
	return 0;	
}	
