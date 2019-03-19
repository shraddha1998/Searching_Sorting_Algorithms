#include<stdio.h>
int profit[50],weight[50],answer[50];
float ratio[50];
void merge(int l, int h)
{
    int a[h],c[h];
    float b[h];
    int i,j,m,k=l;
    i=l;
    j=((l+h)/2)+1;
    m=j-1;
    while (i<=m && j<=h)
    {
      if(ratio[i]>ratio[j])
      {
        b[k]=ratio[i];
        a[k]=weight[i];
        c[k]=profit[i];
        i++;
      }
      else
      {
        b[k]=ratio[j];
        a[k]=weight[j];
        c[k]=profit[j];
        j++;
      }
      k++;
    }

    if(i>m)
    {
      while(j<=h)
      {
        b[k]=ratio[j];
        a[k]=weight[j];
        c[k]=profit[j];
        j++;
        k++;
      }
    }
    else
    {
      while(i<=m)
      {
        b[k]=ratio[i];
        a[k]=weight[i];
        c[k]=profit[i];
        i++;
        k++;
      }
    }
    k=l;
    while(k<=h)
    {
      ratio[k]=b[k];
      weight[k]=a[k];
      profit[k]=c[k];
      k++;
    }

}


void mergesort(int l, int h)
{
  if(h>l)
  {
    mergesort(l,(l+h)/2);
    mergesort(((l+h)/2)+1,h);
    merge(l,h);
  }
}
int knapsack(int n,int capacity)
{
int p=0;
for(int i=0;i<n;i++)
{
	if(weight[i]<=capacity)
	{
	answer[i]=i;
	capacity=capacity-weight[i];
	p=p+profit[i];
	}
	
	else
	{
	answer[i]=i;
	p=p+(capacity*profit[i]/weight[i]);
	break;
	}
}
return p;
}



int main()
{
int n,i,capacity;

printf("Enter the capacity of the bag ");
scanf("%d",&capacity);
printf("Enter the number of items ");
scanf("%d",&n);
printf("Enter profit and weight associated with items\n");
for(i=0;i<n;i++)
{
	printf("Enter profit of item [%d]",i);
	scanf("%d",&profit[i]);
	answer[i]=-1;
	printf("Enter weight of item [%d]",i);
	scanf("%d",&weight[i]);
	ratio[i]=(float)profit[i]/weight[i];
	
}

mergesort(0,n-1);
printf("Sorted array is \n");
for(i=0;i<n;i++)
{
	printf("%f  ",ratio[i]);
}

i=knapsack(n,capacity);
printf("Total profit is %d \n",i);


return 0;
}

/*
user@shraddha:~/Documents/scj124/daa$ gcc -o knap fractionalknapsack.c
user@shraddha:~/Documents/scj124/daa$ ./knap
Enter the capacity of the bag 60
Enter the number of items 5
Enter profit and weight associated with items
Enter profit of item [0]30
Enter weight of item [0]5
Enter profit of item [1]40
Enter weight of item [1]10
Enter profit of item [2]45
Enter weight of item [2]15
Enter profit of item [3]77
Enter weight of item [3]22
Enter profit of item [4]90
Enter weight of item [4]25
Sorted array is 
6.000000  4.000000  3.600000  3.500000  3.000000  Total profit is 230 


*/
