#include<stdio.h>
int arr[100],mid;
int binarysearch(int low,int high,int x)
{
	mid=(low+high)/2;
	if(low<=high)
	{
		if(arr[mid]==x)
		{
			return mid;
		}
		else if(arr[mid]>x)
		{
			return binarysearch(low,mid-1,x);
		}
		else
		{
			return binarysearch(mid+1,high,x);
		}
	}

return -1;
}


int main()
{
int n,i,x;
printf("Enter the number of elements");
scanf("%d",&n);
printf("Enter elements");
for(i=0;i<n;i++)
{
	scanf("%d",&arr[i]);
}
printf("Enter the element to search");
scanf("%d",&x);
int pos=binarysearch(0,n-1,x);
if(pos==-1)
{
	printf("Element not found\n");
}
else
{
	printf("Element found at %d \n",pos+1);
}

return 0;
}
