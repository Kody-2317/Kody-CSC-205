/*A program to show multiple threads with global and static variables*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int grade =
80; // Create a global variable to change it in threads

// The function to be executed by all threads
void *myThreadAdd(void *vargp)
{
	int *myid = (int *)vargp; // Store the value arguement passed to this thread 
	static int age=17; // Create a static variable to observe its changes
	++age; ++grade;	//Change static and global variable
	printf("Thread ID: %d, Age: %d, Grade: %d\n", *myid, ++age, ++grade);
}

int main()
{	
	int i;
	pthread_t tid;
	
	// Let us create three threads
	for (i = 0; i < 5; i++)
		pthread_create(&tid, NULL, myThreadAdd, (void *)&tid);
		pthread_join(tid, NULL);
	pthread_exit(NULL);
	return 0;
}

