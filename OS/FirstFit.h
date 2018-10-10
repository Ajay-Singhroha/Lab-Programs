using namespace std;

class FirstFit
{
	public:
	
	int giveTheFirst(int process,int memory[], int m)
	
	{	
		for(int i=0;i<m;i++)
		{
			if(process<=memory[i])
			return i;
		}
		return -1;	
	}
	
	void firstfit(int process[],int memory[],int p,int m)
	{	
		
		
		for(int i=0;i<p;i++)
		{
			int j=giveTheFirst(process[i],memory,m);
			if(j!=-1)
			{	memory[j]-=process[i];
				process[i]=0;
			}
		}
		
		
	}
	
	
};
