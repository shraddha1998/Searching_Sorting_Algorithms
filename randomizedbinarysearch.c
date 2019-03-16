#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[100],mid;

int getRandom(int x,int y)
{
srand(time(NULL));
return (x+rand()%(y-x+1));
}


int binarysearch(int low,int high,int x)
{
	mid=getRandom(low,high);
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



/*OUTPUT
user@shraddha:~/Documents/scj124/daa$ gcc -o binary randomizedbinarysearch.c
user@shraddha:~/Documents/scj124/daa$ ./binary
Enter the number of elements5
Enter elements1
3
5
7
9
Enter the element to search3
Element found at 2 */

