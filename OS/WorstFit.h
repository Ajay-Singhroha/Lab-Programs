using namespace std;

class WorstFit
{
	public:
	
	int giveTheWorst(int process,int memory[], int m)
	{	int worst=-1;
		for(int i=0;i<m;i++)
		{
			if(process<=memory[i]&&worst==-1)
				worst=i;
			else if(process<=memory[i]&&memory[worst]<memory[i]&&worst!=-1)
				worst=i;
			
		}
		return worst;	
	}
	
	void worstfit(int process[],int memory[],int p,int m)
	{	
		
		for(int i=0;i<p;i++)
		{
			int j=giveTheWorst(process[i],memory,m);
			if(j!=-1)
			{
				memory[j]-=process[i];
				process[i]=0;
			}
		}
		
		
	}
	
	
};
