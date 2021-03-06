#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define cutpoint1 2
#define cutpoint2 6
#define K 10
#define numberOfCity 9
#define numberOfchild 2
#define tNUM 100000

int cost(int array[]){
    int i=0;
    int sum=0;

    for(i=0;i<numberOfCity-1;i++){
        if(array[i]<array[i+1]){
            sum+=array[i+1]-array[i];
        }else{
            sum+=array[i]-array[i+1];


        }

    }

    return sum;

}
int main(){
    srand(time(NULL));
    int flag;
    int c1[numberOfCity];
    int c2[numberOfCity];
    int p1[numberOfCity];
    int p2[numberOfCity];

    int index=cutpoint2-cutpoint1+1;
    int ctemp1[index];
    int ctemp2[index];
    int num[numberOfCity];
    int randtemp1[index];
    int randtemp2[index];
    int set[K][numberOfCity];
    int sum[K];

    int i,j,k,now=0;

    for(i=0;i<numberOfCity;i++){
        c1[i]=0;
        c2[i]=0;
        p1[i]=0;
        p2[i]=0;
    }


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

    int array[K];

    for(i=0;i<K;i++){
        array[i]=i;
    }
    int temp,temp1=0;;

    for(i=0;i<K;i++){
        for(j=i;j<K;j++){
            if(sum[i]>sum[j]){
                temp=sum[i];
                sum[i]=sum[j];
                sum[j]=temp;
                temp1=array[i];
                array[i]=array[j];
                array[j]=temp1;
            }
        }
    }


    printf("Choose %d and %d genetic\n",array[0],array[1]);


    for(i=0;i<numberOfCity;i++){
        p1[i]=set[array[0]][i];
        p2[i]=set[array[1]][i];
    }

    printf("\n");

    //create Child

    while(now<tNUM){

        for(i=0;i<numberOfCity;i++){
            num[i]=i+1;
        }

        for(i=0;i<index;i++){
            ctemp1[i]=0;
            ctemp2[i]=0;
        }

        for(i=cutpoint1+1;i<cutpoint2+1;i++){
            c1[i]=p1[i];
            c2[i]=p2[i];
        }
        for(i=0;i<=cutpoint1;i++){
            ctemp1[i]=p1[i];
            ctemp2[i]=p2[i];
        }

        for(i=cutpoint2+1,k=cutpoint1+1;i<numberOfCity&&k<index;i++,k++){
            ctemp1[k]=p1[i];
            ctemp2[k]=p2[i];
        }
        for(i=0;i<index;i++){
            randtemp1[i]=-1;
            randtemp2[i]=-1;
        }

        for(i=0;i<index;i++){
            while(1){
                randtemp1[i]=rand()%index;
                flag=0;
                for(k=0;k<i;k++){
                    if(randtemp1[i]==randtemp1[k]){
                        flag=1;
                        break;
                    }


                }
                if(!flag){
                    break;
                }

            }
        }

        for(i=0;i<index;i++){
            while(1){
                randtemp2[i]=rand()%index;
                flag=0;
                for(k=0;k<i;k++){
                    if(randtemp2[i]==randtemp2[k]){
                        flag=1;
                        break;
                    }


                }
                if(!flag){
                    break;
                }

            }
        }



        for(i=0;i<=cutpoint1;i++){
            c1[i]=ctemp2[randtemp1[i]];
            c2[i]=ctemp1[randtemp2[i]];
        }

        for(i=cutpoint2+1,k=cutpoint1+1;i<numberOfCity && k<index;i++,k++){
            c1[i]=ctemp2[randtemp1[k]];
            c2[i]=ctemp1[randtemp2[k]];
        }

        for(i=0;i<numberOfCity;i++){
            for(j=i+1;j<numberOfCity;j++){
                if(c1[i]==c1[j]){
                    c1[j]=0;
                }
            }
        }

        for(i=0;i<numberOfCity;i++){
            for(j=i+1;j<numberOfCity;j++){
                if(c2[i]==c2[j]){
                    c2[j]=0;
                }

            }

        }

        int imsi=-1;

        for(i=0;i<numberOfCity;i++){
            for(j=0;j<numberOfCity;j++){
                if(num[i]==c1[j]){
                    flag=0;
                    break;
                }
                if(c1[j]==0){
                    flag=1;
                    imsi=j;

                }
            }
            if(flag)
                c1[imsi]=num[i];
        }

        for(i=0;i<numberOfCity;i++){
            for(j=0;j<numberOfCity;j++){
                if(num[i]==c2[j]){
                    flag=0;
                    break;
                }
                if(c2[j]==0){
                    flag=1;
                    imsi=j;

                }
            }
            if(flag)
                c2[imsi]=num[i];

        }
        if(cost(p1)>cost(c1)){
            for(i=0;i<numberOfCity;i++){
                p1[i]=c1[i];
                c1[i]=0;
            }

        }else{

            for(i=0;i<numberOfCity;i++){
                c1[i]=0;
            }
        }

        if(cost(p2)>cost(c2)){
            for(i=0;i<numberOfCity;i++){
                p2[i]=c2[i];
                c2[i]=0;
            }
        }else{

            for(i=0;i<numberOfCity;i++){
                c1[i]=0;
            }
        }
        now++;

    }

    if(cost(p1)>cost(p2)){

        printf("p2:[");
        for(i=0;i<numberOfCity;i++){
            printf(" %d ",p2[i]);
        }
        printf("]\n");

        printf("cost:%d\n",cost(p2));
    }else{
        printf("p1:[");
        for(i=0;i<numberOfCity;i++){
            printf(" %d ",p1[i]);


        }
        printf("]\n");

        printf("cost:%d\n",cost(p1));
    }











    return 0;
}
