
#include "max_min.h"
int size = 100;
int a[1000] = {};  // creating array of 1000 values
int temp_min_array[10] = {}; //create array to store parallel min values


void * min_body(void* pv)
{
int temp_min=0;
int i,t = (__intptr_t)pv;
for(i=0;i<size;i++){   //adding 100 array values for each thread
if(a[(t*size)+i]<temp_min)
{
temp_min=a[(t*size)+i];
}
}
temp_min_array[t]=temp_min;
//to verify the parallel thread minimum
}


int min_array()
{
int i,n=10,minimum=0;
pthread_t td_array[n];

for(i=0;i<1000;i++){ // assign values to array
a[i]=i;
}

for(i = 0;i<n;i++){  //create 10 thread each stores 100 array values
pthread_create(&td_array[i],NULL,min_body,(void*)(__intptr_t) i);
}

for(i = 0;i<n;i++){
pthread_join(td_array[i], NULL);
}
                 //calculate minimum element from 10 threads

for(i=0;i<n;i++){

if( temp_min_array[i]<minimum )
{
minimum = temp_min_array[i];
}

}
return minimum;
}

