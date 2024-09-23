/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//Signal Types
#define SIGHUP  1 //Hang Up Process
#define SIGINT  2 //Interrupt the Process
#define SIGQUIT 3 //Quit the Process
#define SIGILL  4 //Illegal instruction
#define SIGTRAP 5 //Trace Trap
#define SIGABRT 6 //Abort

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  //Schedule a SIGALRM for 1 second
  alarm(1);
}

int main(int argc, char * argv[])
{
 //register handler to handle SIGALRM
 signal(SIGALRM,handler);
 //Schedule a SIGALRM for 1 second
 alarm(1);
 //busy wait for signal to be delivered
 while(1)
 {
   //Pause the main function's execution to allow the handler to run first
   //awaiting for the signal to be delivered
   pause();
  //Print requested string afterwards
  printf("Turing was right!\n");
 
 }
  //never reached
  return 0; 
}