#include <regex.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void)
{
int fd=open("URL.txt",O_RDWR);
int size=lseek(fd,0,SEEK_END);
char * mmap_ptr=NULL;

mmap_ptr=mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
close(fd);

char link[1024];
char title[1024];

regex_t reg;
char * regstr="<a[^>]\\+\\?href=\"\\([^\"]\\+\\?\\)\"[^>]\\+\\?>\\([^<]\\+\\?\\)</a>";
regcomp(&reg,regstr,0);
int reg_num=3;
regmatch_t match[reg_num];

while(regexec(&reg,mmap_ptr,reg_num,match,0)==0)
{
bzero(link,sizeof(link));
bzero(title,sizeof(title));
snprintf(link,match[1].rm_eo-match[1].rm_so+1,"%s",mmap_ptr+match[1].rm_so);
snprintf(title,match[2].rm_eo-match[2].rm_so+1,"%s",mmap_ptr+match[2].rm_so);
mmap_ptr+=match[0].rm_eo;
printf("匹配结果：title=%s  link=%s\n",title,link);
}
regfree(&reg);

return 0;
}

