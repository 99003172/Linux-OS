
#include "sum_array.h"
int size=100;
int a[1000]={};  // creating array of 1000 values
int temp_sum[10]={}; //create array to store parallel sum values

void * sum_body(void* pv)
{
int i,t=(__intptr_t)pv;
for(i=0;i<size;i++){   //adding 100 array values for each thread
temp_sum[t]+=a[(t*size)+i];
}
//printf("\n the temp sum is %d",temp_sum[t]); to verify the parallel thread sum
}


int parallel_sum()
{
int i,n=10,sum=0;
pthread_t td_array[10];

for(i=0;i<1000;i++){ // assign values to array
a[i]=i;
}

for(i = 0;i<n;i++){  //create 10 thread each stores 100 array values
pthread_create(&td_array[i],NULL,sum_body,(void*)(__intptr_t)i);
}

for(i = 0;i<n;i++){
pthread_join(td_array[i], NULL);
}

for(i=0;i<n;i++){
sum += temp_sum[i];
}
return sum;

}

