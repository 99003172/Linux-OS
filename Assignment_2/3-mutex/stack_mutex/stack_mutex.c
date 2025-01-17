#include "stack_mutex.h"

#define MaxItems 5 
/* Buffersize set to 5 */
#define BufferSize 5

int buf_in = 0;
int buf_out = 0;
int item = 0;
int buffer[BufferSize];

pthread_mutex_t mutex;

void *producer(void *pno) {
  if (buf_in == BufferSize - 1) {
    printf("buffer is full \n");
  } 
  else {
    for (int i = 0; i < MaxItems; i++) {
      item = rand()%5;

      /* insert value item into the buffer */
      buffer[buf_in] = item;
      printf("Producer %d: Insert Item %d at %d\n", *((int *)pno), buffer[buf_in],
             buf_in);
      buf_in = (buf_in + 1) % BufferSize;
     
      pthread_mutex_unlock(&mutex);
    }
  }
}

void *consumer(void *cno) {
  if (buf_out == BufferSize - 1) {
    printf("Consumer wait till producer put data to buffer\n");
  } 
  else {
    int item = 0;
    for (int i = 0; i < MaxItems; i++) {
      pthread_mutex_lock(&mutex);
      /* take one unit of data from the buffer */
      item = buffer[buf_out];
      printf("Consumer %d: Remove Item %d from %d\n", *((int *)cno), item, buf_out);
      buf_out = (buf_out + 1) % BufferSize;
      pthread_mutex_unlock(&mutex);
    }
  }
}

void main() {
  pthread_t pro[5], con[5];
  pthread_mutex_init(&mutex, NULL);

  int arr[5] = {1, 2, 3, 4, 5}; 

  for (int i = 0; i < 5; i++) {
    pthread_create(&pro[i], NULL, (void *)producer, (void *)&arr[i]);
  }
  for (int i = 0; i < 5; i++) {
    pthread_create(&con[i], NULL, (void *)consumer, (void *)&arr[i]);
  }

  for (int i = 0; i < 5; i++) {
    pthread_join(pro[i], NULL);
  }
  for (int i = 0; i < 5; i++) {
    pthread_join(con[i], NULL);
  }
  pthread_mutex_destroy(&mutex);
}
