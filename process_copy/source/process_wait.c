#include<process_copy.h>

void process_wait(void)
{
pid_t zpid;
while((zpid=waitpid(-1,NULL,WNOHANG))>0){
printf("Parent wait child success , zpid %d\n",zpid);
}
}
