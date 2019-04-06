#include<stdio.h>
int res[50];

int canPlace(int row,int col)
{

for(int i=1;i<=row-1;i++)
{
	if(res[i]==col)
	{
		return 0;
	}
	if(abs(res[i]-col)==abs(i-row))
	{
		return 0;
	}
}
return 1;
}

void print_res(int n)
{
printf("\n");
for(int i=1;i<=n;i++)
{
	printf("\n");
	for(int j=1;j<=n;j++)
	{
		if(res[i]==j)
		{
			printf("\tQ");
		}
		else
		{
			printf("\t-");
		}
	}

}

}


void nqueen(int row,int n)
{
	for(int col=1;col<=n;col++)
	{
		if(canPlace(row,col))
		{
			res[row]=col;
			if(row==n)
			{
				print_res(n);
			}
			else
			{
				nqueen(row+1,n);
			}

		}

	}
}



int main()
{
int n,i;
printf("Enter the value of n");
scanf("%d",&n);
for(i=0;i<n+1;i++)
{
	res[i]=0;
}
nqueen(1,n);
printf("\n");
return 0;
}
