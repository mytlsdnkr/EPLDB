
#include <stdio.h>
#include <math.h>
#include <windows.h>
#define e 2.71828
#define hcount 40
#define inputbias 1
#define hbias 1
#define tNum 1000000



double sigmoid(double x){
   
   return 1/(1+1/pow(e,x));

}

double dersigmoid(double x){
    return (2e-1)/pow(pow(e,2)-x+1,2);
}


int main(){
    int result1,result2;
    int inputlayer[15][15];
    int hiddenlayer[hcount];
    int hinj[hcount];
    double deltainJ[hcount][10];
    int outputlayer[10];
    int outiny[10];
    double v[15][15][hcount];
    double vCT[15][15][hcount];
    double w[hcount][10];
    double deltaK[10];
    double deltaJ[hcount];
    double wCT[hcount][10];
    float a=4;
    int targetnumber=9;
    int count=0;
    double sum=0;

    int i,j,k,s=0;

    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            inputlayer[i][j]=0;
        }
    }

    for(k=0;k<hcount;k++){
        hiddenlayer[k]=0;
        hinj[k]=0;

    }
    for(i=0;i<10;i++){
        outputlayer[i]=0;
        outiny[i]=0;
    }
// inputlayer initialize to target number
    inputlayer[2][2]=1;
    inputlayer[2][3]=1;
    inputlayer[2][4]=1;
    inputlayer[2][5]=1;
    inputlayer[2][6]=1;
    inputlayer[2][7]=1;
    inputlayer[2][8]=1;
    inputlayer[2][9]=1;
    inputlayer[2][10]=1;
    inputlayer[3][2]=1;
    inputlayer[4][2]=1;
    inputlayer[5][2]=1;
    inputlayer[5][3]=1;
    inputlayer[5][4]=1;
    inputlayer[5][5]=1;
    inputlayer[5][6]=1;
    inputlayer[5][7]=1;
    inputlayer[5][8]=1;
    inputlayer[5][9]=1;
    inputlayer[5][10]=1;
    inputlayer[6][10]=1;
    inputlayer[7][10]=1;
    inputlayer[8][10]=1;
    inputlayer[9][10]=1;
    inputlayer[8][10]=1;
    inputlayer[7][10]=1;
    inputlayer[6][10]=1;
    inputlayer[5][10]=1;
    inputlayer[4][10]=1;
    inputlayer[3][10]=1;
    inputlayer[2][10]=1;


    while(count<tNum){


        for(i=0;i<15;i++){
            for(j=0;j<15;j++){
                for(s=0;s<hcount;s++){
                    v[i][j][s]=0.8;
                }


            }
            
        }
        for(i=0;i<hcount;i++){
            for(j=0;j<10;j++){
                w[i][j]=0.8;
            }
        }
        while(s<hcount){

            for(i=0;i<15;i++){
                for(j=0;j<15;j++){
                       sum+= inputlayer[i][j]*v[i][j][s];
                    

                }   
            
            }
            
            hinj[s]=sigmoid(sum+inputbias);
            hiddenlayer[s]=hinj[s];
            sum=0;
            s++;

        }
        sum=0;
        s=0;
        while(s<10){
            for(i=0;i<hcount;i++){
                    sum+=hiddenlayer[i]*w[i][s];
            }
            outiny[s]=sigmoid(sum+hbias);
            outputlayer[s]=outiny[s];
            sum=0;
            s++;
        }
        s=0;
        sum=0;

        for(i=0;i<10;i++){
            deltaK[i]=(targetnumber-outputlayer[i])*dersigmoid(outiny[i]);
        }
        
        for(i=0;i<hcount;i++){
            for(j=0;j<10;j++){
                wCT[i][j]=a*deltaK[j]*hiddenlayer[i];

            }
        }

        for(i=0;i<hcount;i++){
            for(j=0;j<10;j++){
                deltainJ[i][j]=deltaK[j]*w[i][j];

            }
        }

        for(i=0;i<hcount;i++){
            deltaJ[i]=deltainJ[i][0]*w[i][0]+deltainJ[i][1]*w[i][1]+deltainJ[i][2]*w[i][2]+deltainJ[i][3]*w[i][3]+deltainJ[i][4]*w[i][4]+deltainJ[i][5]*w[i][5]+deltainJ[i][6]*w[i][6]+deltainJ[i][7]*w[i][7]+deltainJ[i][8]*w[i][8]+deltainJ[i][9]*w[i][9];
/*            for(j=0;j<10;j++){
                deltaJ[i]+=delta_inj[i][j]*w[i][j];
            }*/

        }

        for(i=0;i<15;i++){
            for(j=0;j<15;j++){
                for(k=0;k<hcount;k++){
                    vCT[i][j][k]=a*deltaJ[k]*inputlayer[i][j];
                    
                }
            }
        }

        for(i=0;i<hcount;i++){
            for(j=0;j<10;j++){
                w[i][j]=w[i][j]+wCT[i][j];
            }
        }

        for(i=0;i<15;i++){
            for(j=0;j<15;j++){
                for(k=0;k<hcount;k++){
                    v[i][j][k]=v[i][j][k]+vCT[i][j][k];
                }
            }
        }


        count++;
        




    }
    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            if(inputlayer[i][j]==0){
                printf("■ ");
            }
            else{
                printf("□ ");
            }
        }
        printf("\n");
    }

    printf("\n");

    sum=0;

    for(i=0;i<hcount;i++){
        for(j=0;j<10;j++){
            sum+=w[i][j];
        }
    }

    sum=sum/400;

    result1=sum;


    sum=0;

    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            for(k=0;k<hcount;k++){

                sum+=v[i][j][k];
            }
        }
    }

    
    sum=sum/400;

    result2=sum;



    printf("학습된 값:%d\n",(result1+result2)/2);

    




	system("pause");
    return 0;
}

