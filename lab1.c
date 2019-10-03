#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int brute_force();
char t[30],p[30];

void main()
{
	struct timeval s,e;
	//clock_t tm;
	int pos,flag=1;
	FILE *fp;
	//fp=fopen("sample.txt","a+");
	while(flag==1)
	{
		fp=fopen("lab1.txt","a+");
		printf("Enter the source string\n");
		gets(t);
		printf("Enter the pattern\n");
		gets(p);
		gettimeofday(&s,0);
		pos=brute_force();
		gettimeofday(&e,0);
		if(pos==-1)
			printf("Not found\n");
		else
			printf("Found at %d position\n",pos);
		int n=strlen(t);
		double tt=e.tv_usec-s.tv_usec;
		fprintf(fp,"%d\t\t %f\n",n,tt);
		printf("Time taken=%f\n",tt);
		printf("Do u want to continue?press 1 to continue or 0 to exit\n");
		scanf("%d",&flag);
		if(flag==1)
			flag=1;
		else
			flag=0;
	}
}
int brute_force()
{
	int i,j,m,n;
	n=strlen(t);
	m=strlen(p);
	for(i=0;i<n;i++)
		{
		j=0;
		while(j<m && t[i+j]==p[j])
			{
				j++;
				if(j==m)
					{
					return i+1;
					}
			}
		}
	return -1;
}
