#include <iostream>

using namespace std;
#define BUFFER_SIZE 10
typedef struct{
} item;
item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int main()
{
	item nextProduced;
	while (true)
	{
		/* produce an item in nextProduced */
		while ( ((in + 1) % BUFFER_SIZE) == out)
			;
		/* do nothing */
		buffer[in] = nextProduced;
		in = (in + 1) % BUFFER_SIZE;
	}

	item nextConsumed;
	while (true)
	{
		while (in == out)
			;/* do nothing*/
		nextConsumed = buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		/* consume the item in nextConsumed*/
	}
	return 0;
}
