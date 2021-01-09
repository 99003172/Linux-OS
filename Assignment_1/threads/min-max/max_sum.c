
int size = 100;
int a[1000] = {};  // creating array of 1000 values
int temp_max_array[10] = {}; //create array to store parallel max values

void * max_body(void* pv)
{
int i,t = (__intptr_t)pv;
int temp_max=0;
for(i=0;i<size;i++){   //adding 100 array values for each thread
if(a[(t*size)+i]>temp_max)
{
temp_max=a[(t*size)+i];
}
}

temp_max_array[t]=temp_max;
}


int max_array()
{
int i,n=10,maximum=0;
pthread_t td_array[10];

for(i=0;i<1000;i++){ // assign values to array
a[i]=i;
}

for(i = 0;i<n;i++){  //create 10 thread each stores 100 array values
pthread_create(&td_array[i],NULL,max_body,(void*)(__intptr_t)i);
}

for(i = 0;i<n;i++){
pthread_join(td_array[i], NULL);
}
                 //calculate maximum element from 10 threads

for(i=0;i<n;i++){
if( temp_max_array[i]>maximum )
{
maximum = temp_max_array[i];
}

}
return maximum;
}

