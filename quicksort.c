#include<stdio.h>

void display(int arr[],int n)
{
for(int i=0; i<n; i++)
     	{
        	  printf("%d ",arr[i]);
         
        }
printf("\n");
}

int partition(int arr[],int low,int high,int n)
{
	int p,temp;
	int i,j;
	p=arr[low];
	i=low+1;
	j=high;
	while(1)
	{
	while(arr[i]<p)
	{
		i++;
	}
	while(arr[j]>p)
	{
		j--;
	}
	if(i<j)
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		display(arr,n);
	}
	else
	{
		arr[low]=arr[j];
		arr[j]=p;
		display(arr,n);
		break;
	}
	}
return j;
}


void quicksort(int arr[],int low,int high,int n)
{
	int pos;
	if(low<high)
	{
		pos=partition(arr,low,high,n);
		quicksort(arr,low,pos-1,n);
		quicksort(arr,pos+1,high,n);
	}
}

int main()
{ 
	int n;
	int arr[50];
	printf("Enter number of elements: ");
	scanf("%d", &n);
     	for(int i=0; i<n; ++i)
     	{	
        	  printf("Enter %dst element: ",i+1);
        	  scanf("%d", &arr[i]);
          
     	}
	display(arr,n);
	quicksort(arr,0,n-1,n);
	printf("Sorted array is\n");
 	for(int i=0; i<n; i++)
     	{
        	  printf("%d ",arr[i]);
         
        }
return 0;
}

/*OUTPUT
user@shraddha:~/Documents/scj124/daa$ ./q
Enter number of elements: 5
Enter 1st element: 3
Enter 2st element: 5
Enter 3st element: 1
Enter 4st element: 2
Enter 5st element: 4
3 5 1 2 4 
3 2 1 5 4 
1 2 3 5 4 
1 2 3 5 4 
1 2 3 4 5 
Sorted array is
1 2 3 4 5 
*/
