#include <sys/time.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#define max 100000

int a[175000];
int b[175000];
unsigned int comp = 0;
unsigned int ass = 0;
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
	ass++;
    *xp = *yp;
	ass++; 
    *yp = temp; 
	ass++;
} 
  
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++) {      
    
       for (j = 0; j < n-i-1; j++){  
	comp++; 
           if (arr[j] > arr[j+1]) {
		           
		  swap(&arr[j], &arr[j+1]); 
	
	}
	}
   }
} 
 
/*void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
*/
int main(int argc, char *argv[])
{
int i;
for(i = 0; i<175000; i++) 
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

start = tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 + tm->tm_sec * 1000 + tv.tv_usec / 1000;

//for (x=0;x<5000000000;x++)
//;
bubbleSort(a, size-1);

gettimeofday(&tv, &tz);
tm = localtime(&tv.tv_sec);
stop = tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
tm->tm_sec * 1000 + tv.tv_usec / 1000;

printf("TIMESTAMP-END\t %d:%02d:%02d:%d (~%d ms) \n", tm->tm_hour,
tm->tm_min, tm->tm_sec, tv.tv_usec,
tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
tm->tm_sec * 1000 + tv.tv_usec / 1000);

printf("ELAPSED\t %d ms\n", stop - start);
 printf("\nList after sorting\n");
   //for(i = 0; i <size; i++)
     // printf("%d ", a[i]);

printf("\ncomparison amount is %lu",comp);
printf("\nassigment amount is %lu", ass);

return 0;
}

