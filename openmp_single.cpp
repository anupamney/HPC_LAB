#include<stdio.h>
#include<omp.h>


int main()
{

	int f=0;	
	
   #pragma omp parallel for shared(f) num_threads(4)
   for(int i=0;i<10;i++)
   {
   	if(f==0)
   	{
	   	printf("Thread number %d\n",omp_get_thread_num());

	   	f=1;
   	}
   	
   	
   	printf("two\n");
   }
   printf("number of threads %d\n",omp_get_num_threads());
}
