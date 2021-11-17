#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//A normal C function that is executed as a thread
// wgen its name is specified in pthread_create()
void *myFirstThread()

{
	sleep(1);
	printf("I am the Thread\n");
	return NULL;
}

int main()
{
	pthread_t thread_id;
	printf("Before Thread Execution\n");
	pthread_create(&thread_id, NULL, myFirstThread, NULL);
	pthread_join(thread_id, NULL);
	exit(0);
}


