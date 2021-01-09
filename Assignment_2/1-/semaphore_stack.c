#include "stack_semaphore.h"

#define MaxItems 5 
/* Buffersize set to 5 */
#define BufferSize 5

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int item = 0;
int buffer[BufferSize];

void *producer(void *pno) {
  if (in == BufferSize - 1) {
    printf("Producer Stack is full \n");
  } 
  else {
    for (int i = 0; i < MaxItems; i++) {
      item = rand();
      sem_wait(&empty);
      /* put value item into the buffer */
      buffer[in] = item;
      printf("Producer %d: Insert Item %d at %d\n", *((int *)pno), buffer[in],
             in);
      in = (in + 1) % BufferSize;
      sem_post(&full);
    }
  }
}

void *consumer(void *cno) {
  if (out == BufferSize - 1) {
    printf("Consumer Stack is full\n");
  } 
  else {
    int item = 0;
    for (int i = 0; i < MaxItems; i++) {
      sem_wait(&full);
      /* take one unit of data from the buffer */
      item = buffer[out];
      printf("Consumer %d: Remove Item %d from %d\n", *((int *)cno), item, out);
      out = (out + 1) % BufferSize;
      sem_post(&empty);
    }
  }
}

void main() {
  pthread_t pro[5], con[5];
  sem_init(&empty, 0, BufferSize);
  sem_init(&full, 0, 0);

  int a[5] = {1, 2, 3, 4, 5}; 

  for (int i = 0; i < 5; i++) {
    pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
  }
  for (int i = 0; i < 5; i++) {
    pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
  }

  for (int i = 0; i < 5; i++) {
    pthread_join(pro[i], NULL);
  }
  for (int i = 0; i < 5; i++) {
    pthread_join(con[i], NULL);
  }

  sem_destroy(&empty);
  sem_destroy(&full);
}