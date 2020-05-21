#include<stdio.h>
#include<pthread.h>

void* func(void* arg) 
{ 
	// detach the current thread 
	// from the calling thread 
	printf("Inside the thread .>>>:%d\n", *(char*)arg); 

	pthread_exit(NULL);
	// exit the current thread 
} 

int main()
{
	pthread_t ptid;
	char a=256; 
	// Creating a new thread 
	pthread_create(&ptid, NULL, &func, (void*)&a);
	printf("In Main\n");

	pthread_join(ptid,NULL);
	return 0;
}
