#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
void *time_funct(void* pv)
{
  int i=0;
  time_t t;
  struct tm* current_time;
  /* Get current time in seconds */
  t = time(NULL);
  /* Change the format to hh : mm : ss*/
  current_time = localtime(&t);
  printf("%02d : %02d : %02d \n",current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

}
void DisplayTime()
{
  int i, n=10;
  pthread_t ptrarr[n];

  for(i=0; i<n; ++i)
  {
    /* Create a thread to get current time */
    pthread_create(&ptrarr[i], NULL, time_funct, (void *)(__intptr_t)i);
    /* Sleep for 3 seconds */
    sleep(5);
  }
  for(i=0; i<n; i++)
  {
    pthread_join(ptrarr[i], NULL);
  }
}
