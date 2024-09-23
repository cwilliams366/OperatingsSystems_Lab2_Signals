/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

//Variable for counting the amount of alarms
int total_alarms = 0;
//Variable for calculating the program's runtime in seconds
double total_time = 0.0;
//Variable to hold total of clock ticks
clock_t clock_ticks, start_time;

void AlarmHandler(int signum)
{ //signal handler
  total_alarms++;
}

void InterruptHandler(int signum)
{
  clock_t end_time = clock();
  total_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Total number of alarms: %d\n",total_alarms);
  printf("Program Endtime: %f seconds\n",total_time);
  exit(signum);
}

int main(int argc, char * argv[])
{
  //Start timer
   start_time = clock();
  //register handler to handle SIGALRM
  signal(SIGALRM,AlarmHandler);
  //register handler to handle SIGINT
  signal(SIGINT,InterruptHandler);
  //busy wait for signal to be delivered
  while(1)
  {
    //Schedule a SIGALRM for 1 second
    alarm(1);
    pause();
  }
  //never reached
  return 0; 
}