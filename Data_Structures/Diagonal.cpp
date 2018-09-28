#include<iostream>
using namespace std;
# define MAX 30
class Diagonal
{
	private:
		int arr[MAX];
		int size;
	public:
		Diagonal(int s)
		{
			size=s;
			int i=0;
			while(i<size)
			{	arr[i]=0;
				i++;
			}
		}
		void set(int i,int value)
		{
			arr[i]=value;
		}
		int get(int i)
		{
			return arr[i];
		}
};
int main()
{	int s,value,i,j,choice;
	cout<<"\n Enter Size of Matrix :: ";
	cin>>s;
	Diagonal d(s);
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
			case 1: cout<<"\n Enter Values :: ";
				for(int i=0;i<s;i++)
				{
					cout<<"\n Enter for A["<<i+1<<"]["<<i+1<<"] :: ";
					cin>>value;
					d.set(i,value);
				}
				break;
			case 2: cout<<"\n Enter Index Values : ";
				try
				{
				
					cout<<"\n Index Value of i :: ";
					cin>>i;
					cout<<"\n Index Value of j :: ";
					cin>>j;
					if(i>s||j>s||i<=0||j<=0)
						throw i;
					else
					{
						if(i==j)
						cout<<"\n Value ::"<<d.get(i-1);
						else
						cout<<"\n Value :: 0 ";
					}
				}
				catch(int error)
				{
					cout<<"\n Error ,Wrong Index Value ! ";
					return 0;
				}
				
				break;
			case 3:cout<<"\n";
				for(int i=0;i<s;i++)
				{
					for(int j=0;j<s;j++)
					{
						if(i==j)
							cout<<""<<d.get(i)<<" ";
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
	
	
	
