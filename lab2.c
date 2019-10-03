#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void quicksort(int [],int,int);
FILE *fp;
void main()
{

	int arr[20],i,j,iter,size,k;
	struct timeval s,e;
	fp=fopen("lab2.txt","a+");
	printf("Enter the num of iteration\n");
	scanf("%d",&iter);
	for(j=0;j<iter;j++)
		{
			printf("Enter the size of te array\n");
			scanf("%d",&size);
			for(i=0;i<size;i++)
				{
					arr[i]=rand()%1000;
				}
			printf("The Elements are\n");
			for(i=0;i<size;i++)
				{
					printf("%d\t",arr[i]);
				}
			printf("\n");
			gettimeofday(&s,0);
			quicksort(arr,0,size-1);
			gettimeofday(&e,0);
			printf("Sorted elements are\n");
			for(i=0;i<size;i++)
				{
					printf("%d\t",arr[i]);
				}
			printf("\n\n\n");
			k=e.tv_usec-s.tv_usec;
			fprintf(fp,"%d\t %d\n",size,k);
		}


}

void quicksort(int arr[100],int low,int high)
{
	int i,j,pivot,temp;
	if(low<high)
		{
			pivot=low;
			i=low;
			j=high;
			while(i<j)
				{
					while(arr[i]<=arr[pivot] && i<=high)
						i++;
					while(arr[j]>arr[pivot] && j>=low)
						j--;
					if(i<j)
						{
						temp=arr[i];
						arr[i]=arr[j];
						arr[j]=temp;
						}
				}
			temp=arr[j];
			arr[j]=arr[pivot];
			arr[pivot]=temp;
			quicksort(arr,low,j-1);
			quicksort(arr,j+1,high);
		}
}
