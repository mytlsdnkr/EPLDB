#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define cutpoint1 2
#define cutpoint2 6
#define K 10
#define numberOfCity 9

int main(){
    srand(time(NULL));
    int flag;

    int set[K][numberOfCity];
    int sum[K];

    int i,j,k=0;

    
    for(i=0;i<K;i++){
        sum[i]=0;
    }

    for(i=0;i<K;i++){
        for(j=0;j<numberOfCity;j++){
            while(1){
                set[i][j]=(rand()%numberOfCity)+1;
                flag=0;

                for(k=0;k<j;k++){
                    if(set[i][j]==set[i][k]){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
        }
    }

    for(i=0;i<K;i++){
        for(j=0;j<numberOfCity-1;j++){
            if(set[i][j+1]<set[i][j]){
                sum[i]+=set[i][j]-set[i][j+1];
            }else{

                sum[i]+=set[i][j+1]-set[i][j];
            }
        }
    }

    for(i=0;i<K;i++){
        printf("P[%d]={ ",i);
        for(j=0;j<numberOfCity;j++){
            printf(" %d ",set[i][j]);
           
        }
        printf("}\n");
    }

    for(i=0;i<K;i++){
        printf("sum[%d]=%d\n",i,sum[i]);
        

    }


   

return 0;
}
