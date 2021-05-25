#include <sys/time.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#define max 100000

int a[200000];
int b[200000];
unsigned int comp = 0;
unsigned int ass = 0;

void quick_sort(int a[],int l,int u)
{
    int j;
	comp++;
    if(l<u)
    {
	
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}
 
int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;

    j=u+1;
	
    
    do
    {
        do{
            i++;
            comp++;}
        while(a[i]<v&&i<=u);
		comp++;
        
        do{
            j--;
	comp++;}
        while(v<a[j]);
		comp++;
        comp++;
        if(i<j)
        {
		
            temp=a[i];
	ass++;
            a[i]=a[j];
	ass++;
            a[j]=temp;
	ass++;
        }
    }while(i<j);
	comp++;
    
    a[l]=a[j];
	ass++;
    a[j]=v;
	ass++;    
    return(j);
}


int main(int argc, char *argv[])
{
    /*int a[50],n,i;
    printf("How many elements?");
    scanf("%d",&n);
    printf("\nEnter array elements:");
    
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        
    quick_sort(a,0,n-1);
    printf("\nArray after sorting:");
    
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    
    return 0;   */
 
 int i;
for(i = 0; i<200000; i++) 
       a[i]=rand(); 
//printf("List before sorting\n");

	int size=sizeof(a)/sizeof(a[0]);
	//printf("size is%d\n",size);


  // printf("\nList after sorting\n");     

struct timeval time;
struct timezone timez;
int rc;
long x;
struct timeval tv;
struct timezone tz;
struct tm *tm;
long start,stop;

gettimeofday(&tv, &tz);
tm = localtime(&tv.tv_sec);
printf("TIMESTAMP-START\t %d:%02d:%02d:%d (~%d ms)\n", tm->tm_hour,
tm->tm_min, tm->tm_sec, tv.tv_usec,
tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
tm->tm_sec * 1000 + tv.tv_usec / 1000);

start = tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 + tm->tm_sec * 1000       + tv.tv_usec / 1000;

//for (x=0;x<5000000000;x++)
//;
quick_sort(a, 0, size-1);

gettimeofday(&tv, &tz);
tm = localtime(&tv.tv_sec);
stop = tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
tm->tm_sec * 1000 + tv.tv_usec / 1000;

printf("TIMESTAMP-END\t %d:%02d:%02d:%d (~%d ms) \n", tm->tm_hour,
tm->tm_min, tm->tm_sec, tv.tv_usec,
tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
tm->tm_sec * 1000 + tv.tv_usec / 1000);

printf("ELAPSED\t %d ms\n", stop - start);
// printf("\nList after sorting\n");
  // for(i = 0; i <size; i++)
    //  printf("%d ", a[i]);
printf("\ncomparison amount is %lu",comp);
printf("\nassigment amount is %lu", ass);
return 0;
}
