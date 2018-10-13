#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[] ){
    srand((unsigned)time(NULL));

    

    if(argc==1){
        printf("You don't input filename to encrypt");
        exit(1);
    }
    char c;
    int fd,key;
    fd=open(argv[1],O_RDWR);

    key=(rand()%26)+1;

    
    while(read(fd,&c,1)==1){
        if('a'<=c && c<='z'){
            c=((c-'a'+key)%26+'a');
        }
        else if('A'<=c && c<='Z'){
            c=((c='A'+key)%26+'A');
        }
        lseek(fd,-1,SEEK_CUR);
        write(fd,&c,1);
    }
    
    printf("encrypt is completed. %d \n",key);
    close(fd);
    

    exit(1);
}

    

