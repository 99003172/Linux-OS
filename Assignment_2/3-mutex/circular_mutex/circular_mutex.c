#include "circular_mutex.h"

#define MaxItems 5 
#define BufferSize 5 // Size of the buffer


int buf_in = 0;
int buf_out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pno)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand()%5; // Produce a random item

        pthread_mutex_lock(&mutex);
        /* wait for space in buffer */
        while (((buf_in + 1) % BufferSize) == buf_out)
        {
        /* put value item into the buffer */
           buffer[buf_in] = item;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[buf_in],buf_in);
           buf_in = (buf_in + 1) % BufferSize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *cno)
{   
    int item=0;
    for(int i = 0; i < MaxItems; i++) {

        pthread_mutex_lock(&mutex);
        /* wait for buffer to fill */
        while (buf_in == buf_out) 
        {
        /* take one unit of data from the buffer */
           item = buffer[buf_out];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, buf_out); 
           buf_out = (buf_out + 1) % BufferSize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{   

    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);
    

    int arr[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&arr[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&arr[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    

    return 0;
}