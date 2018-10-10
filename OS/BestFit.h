using namespace std;

class BestFit
{
	public:
	
	int giveTheBest(int process,int memory[], int m)
	
	{	int best=-1;
		for(int i=0;i<m;i++)
		{
			if(process<=memory[i]&&i==0)
				best=i;
			else if(process<=memory[i]&&memory[best]>memory[i])
				best=i;
			
		}
		return best;	
	}
	
	void bestfit(int process[],int memory[],int p,int m)
	{	
		
		for(int i=0;i<p;i++)
		{
			int j=giveTheBest(process[i],memory,m);
			if(j!=-1)
			{
				memory[j]-=process[i];
				process[i]=0;
			}
		}
		
		
	}
	
	
};
