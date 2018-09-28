#include<iostream>
using namespace std;
# define MAX 30
class Symmetric
{
	private:
		int arr[MAX];
		int size;
	public:
		Symmetric(int s)
		{
			size=s*(s+1)/2;
			int i=0;
			while(i<size)
			{	arr[i]=0;
				i++;
			}
		}
		void set(int i,int j,int value)
		{
			arr[i*(i+1)/2+j]=value;
		}
		int get(int i,int j)
		{
			return arr[i*(i+1)/2+j];
		}
};
int main()
{	int s=0,value=0,i=0,j=0,choice=0;
	cout<<"\n Enter Size of Matrix :: ";
	cin>>s;
	Symmetric d(s);
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
			case 1: cout<<"\n Enter Values (for Lower Tri Entries Only ,Upper Entries will set automatically) :: ";
				for(int i=0;i<s;i++)
				{
					for(int j=0;j<=i;j++)
						{
							cout<<"\n Enter for A["<<i+1<<"]["<<j+1<<"] :: ";
							cin>>value;
							d.set(i,j,value);
						}
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
						if(i>=j)
							cout<<"\n Value ::"<<d.get(i-1,j-1);
						else
							cout<<"\n Value :: "<<d.get(j-1,i-1);
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
						if(i>=j)
							cout<<""<<d.get(i,j)<<" ";
						else
							cout<<""<<d.get(j,i)<<" ";
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
	
	
	
