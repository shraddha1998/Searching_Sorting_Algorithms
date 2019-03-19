#include<stdio.h>


void merge(int arr[],int low,int mid,int high)
{
int b[100],i,j,k;
i=low;
k=low;
j=mid+1;

while(i<=mid && j<=high)
{
	if(arr[i]<arr[j])
	{
		b[k]=arr[i];
		k++;
		i++;
	}
	else
	{
		b[k]=arr[j];
		k++;
		j++;
	}
}

	if(i>mid)
	{
		while(j<=high)
		{
			b[k]=arr[j];
			k++;
			j++;	
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=arr[i];
			k++;
			i++;	
		}
	}


	while(low<=high)
	{
		arr[low]=b[low];
		low++;
	}

}


void mergesort(int arr[],int low,int high)
{
int mid;

	if(low<high)
	{
	mid=(low+high)/2;
	mergesort(arr,low,mid);
	mergesort(arr,mid+1,high);
	merge(arr,low,mid,high);
	}
}



int main()
{
int n,i,x,arr[100];
printf("Enter the number of elements ");
scanf("%d",&n);
printf("Enter elements \n");
for(i=0;i<n;i++)
{
	scanf("%d",&arr[i]);
}
mergesort(arr,0,n-1);
printf("Sorted array is \n");
for(int i=0;i<n;i++)
{
	printf("%d  ",arr[i]);
}
return 0;
}


/*OUTPUT

user@shraddha:~/Documents/scj124/daa$ gcc -o merge mergesort.c
user@shraddha:~/Documents/scj124/daa$ ./merge
Enter the number of elements 5
Enter elements
3
1
2
5
4
Sorted array is 
1  2  3  4  5 



*/




