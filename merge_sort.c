#include <sys/time.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#define max 100000
int a[100000000];
int b[100000000];
unsigned int comparison = 0;
unsigned int assignment = 0;

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
		comparison++;      
	if(a[l1] <= a[l2]){
         b[i] = a[l1++];
	assignment++;
	}
      else{
         b[i] = a[l2++];
	assignment++;	
	}   
     }
   
   while(l1 <= mid) {   
	comparison++;
      b[i++] = a[l1++];
	assignment++;
   }
   while(l2 <= high) {  
	comparison++;   
	   b[i++] = a[l2++];
	assignment++;   
	}

   for(i = low; i <= high; i++){
	comparison++; 
     a[i] = b[i];
	assignment++; 
    }
}

void sort(int low, int high) {
   int mid;
   comparison++; 
   if(low < high) {
	
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int main(int argc, char *argv[])
{

for(int i=0; i<100000000; i++){
	a[i] = rand();
}

printf("List before sorting\n");
   int i;
	int size=sizeof(a)/sizeof(a[0]);
	/*printf("size is%d\n",size);
   for(i = 0; i <size; i++)
      printf("%d ", a[i]);

   printf("\nList after sorting\n");
   */

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
sort(0, size-1);

  
gettimeofday(&tv, &tz);
tm = localtime(&tv.tv_sec);
stop = tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
tm->tm_sec * 1000 + tv.tv_usec / 1000;

printf("TIMESTAMP-END\t %d:%02d:%02d:%d (~%d ms) \n", tm->tm_hour,
tm->tm_min, tm->tm_sec, tv.tv_usec,
tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
tm->tm_sec * 1000 + tv.tv_usec / 1000);

printf("ELAPSED\t %d ms\n", stop - start);
 /*printf("\nList after sorting\n");
   for(i = 0; i <size; i++)
      printf("%d ", a[i]);
*/
printf("\ncomparison amount is %lu",comparison);
printf("\nassignment amount is %lu",assignment);

return 0;
}
