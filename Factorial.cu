#include<stdio.h>
#include<iostream>
using namespace std;
__managed__ int ans=1;
__global__ void Factorial(int *gpu_num,long int *gpu_res)
{
//	int id = threadIdx.x;
  *gpu_res=1;
  for(int i=1;i<=*gpu_num;i++)
  {
    *gpu_res = *gpu_res * i;      
  }
}

int main()
{
  int Number;
  int *dev_number;
  long int *res, result;
  system("clear");
  printf("\n\t Enter the number : ");
  scanf("%d",&Number);
  cudaMalloc((void**)&dev_number,sizeof(int));
  cudaMalloc((void**)&res,sizeof(long int));
  

  cudaMemcpy(dev_number,&Number,sizeof(int),cudaMemcpyHostToDevice);
 

  Factorial<<<1,100>>>(dev_number,res);
	
  cudaMemcpy(&result,res,sizeof(long int),cudaMemcpyDeviceToHost);


  printf("\n\t Factorial of number %d is %ld \n",Number,result);  
  cudaFree(dev_number);
  return 0; 
}

