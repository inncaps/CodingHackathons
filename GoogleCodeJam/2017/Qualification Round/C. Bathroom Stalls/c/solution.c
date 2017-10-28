#include <stdio.h>
#include <stdlib.h>



void findk(long long int n,long long int k, long long int *minLR,long long int *maxLR)
{
	if(k==1)
	{
		(*maxLR)=n/2;
		(*minLR)=(n-1)/2;
	}

	else
	{
		if(k%2==0)
		{
			findk(n/2,k/2,minLR,maxLR);
		}

		else
		{
			findk((n-1)/2,k/2,minLR,maxLR);
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		long long int n,k;
		long long int maxLR, minLR;
		scanf("%Ld%Ld",&n,&k);
		findk(n,k,&minLR,&maxLR);
		printf("#Case %d:\t%Ld %Ld\n",i+1,maxLR,minLR );
	}

	
	return 0;
}
