#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc , char *argv[]){
    
    char c;
    int key,fd,count;
    count=0;
    if(argc==1){
        printf("You don't input option.");
        exit(1);
    }
    fd=open(argv[1],O_RDWR);

    for(key=1;key<27;key++){
        printf("key:%d\n\n",key);
        while(read(fd,&c,1)==1){
            if('a'<=c && c<='z'){
                c=(c-'a'+26-key)%26+'a';
            }else if('A'<=c && c<='Z'){
                c=(c-'A'+26-key)%26+'A';
            }
            printf("%c",c);
            count++;
        }
        printf("\n\n");
        lseek(fd,-1*count,SEEK_CUR);
        count=0;
   }
    close(fd);
    exit(1);
}
            

    

