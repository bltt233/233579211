#include<stdio.h>
#include<unsitd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/type.h>
#include<sys/stat.h>
#include<sys/fcntl.h>

int main(int argc,char ** argv)
{
int sfd;
int dfd;
int offset=atoi(argv[3]);
int blocksize=atoi(argv[4]);
if((sfd=open(argv[1],0,RDONLY))==-1)
perror("open srcfile , failed");
if((dfd=open(argv[2],0,WRONLY|O_CREAT,0664))==-1)
perror("open srcfile , failed");
lseek(sfd,offest,SEEK_SET);
lseek(dfd,offest,SEEK_SET);

char buffer[blocksize];
int len;
printf("child p %d execl Copy , offest %d blocksize %d\n",getpid(),offset,blocksize);
len=read(sfd,buffer,sizeof(buffer));
write(dfd,buffer,len);
close(sfd);
close(dfd);

return 0;
}

