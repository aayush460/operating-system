//assignment 2.a
//execution of merge and quick sort by fork()

#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h>

int partition(int a[], int p ,int r)
{
	int x = a[r];
	int i =p;
	for(int j =p;j<=(r-1);j++)
	{
		if(a[j]<=x)
		{
			if(i==j)
			{
				i++;
				continue;
			}
			int temp = a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
		}
	}
	int temp = a[i];
	a[i]=a[r];
	a[r]=temp;
	return i;
}

 void quicksort(int a[] , int p , int r)
{
	if(p<r)
	{
	int q=partition(a,p,r);
	quicksort(a,p,q-1);
	quicksort(a,q+1,r);
	}
}


void merge(int a[],int p,int q,int r)
{
	int m = q-p+1;
	int n = r-q;
	int l[m],ri[n];
	int x=0;
	for(int i =p;i<=q;i++)
	{
		l[x++]=a[i];
	}
	int y=0;
	for(int i=q+1;i<=r;i++)
	{
		ri[y++]=a[i];
	}
	int i=0,j=0,k=p;
	while(i<m && j<n){
		if(l[i]<ri[j])
		{
		   a[k]=l[i];
		   i++;
		   k++;
		}
		else if(l[i]>ri[j])
		{
			a[k]=ri[j];
			j++;
			k++;
		}
		else{
			a[k]=l[i];
			i++;
			j++;
			k++;
		}
		
	}
	if(i==m && j==n)
	{
		return;
	}
	if(i==m )
	{
	   while(j<n)
	   {
	   	a[k]=ri[j];
	   	j++;
	   	k++;
	   }
	}
	else{
		 while(i<m)
	   {
	   	a[k]=l[i];
	   	i++;
	   	k++;
	   }
	}
}

void mergeSort(int a[] ,int p,int r)
{
	if(p<r)
	{
		int q =(p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);
		merge(a,p,q,r);
	}
}
int main() {
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i =0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	pid_t pid = fork();
	if(pid==0)
	{
		printf("Merge sort in child process\n");
		mergeSort(arr,0,n-1);
   
	    printf("Array after sorting\n");
	    for(int i =0;i<n;i++)
	    {
	   	printf("%d ",arr[i]);
	    }
	    printf("\n");
	}
	else{
		printf("Waiting for child process to finish\n");
		wait(NULL);
		printf("Quick sort in parent process\n");
		quicksort(arr, 0, n-1);
		printf("Array after sorting\n");
        for(int i =0;i<n;i++)
        {
        	printf("%d ",arr[i]);
         }
        printf("\n");
	}
	printf("Bye from %d process\n", pid );
	
	return 0;
}
