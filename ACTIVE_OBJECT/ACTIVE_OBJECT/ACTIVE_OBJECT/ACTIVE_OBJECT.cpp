#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers/servant.h"
#include "helpers/queue_win.h"
#include "helpers/queue.h"
#include "helpers/scheduler.h"
#include "helpers/proxy.h"


//#include "proxy.h"


void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}

int main()
{
     proxy p = proxy(10);
     message_future f = p.execute_pos_sw();
     message m = f.result();
     m.print();
	/*pthread_t thread1, thread2;
     const char *message1 = "Thread 1";
     const char *message2 = "Thread 2";
     int  iret1, iret2;

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); */
	 
	return 0;
}



