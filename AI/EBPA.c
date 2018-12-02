#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define hcount 41
#define inputbias 1
#define hbias 1.0
#define tNum 10000

double sigmoid(double x){

    return 1.0/(1.0+exp(-x));

}

double dersigmoid(double x){
    return (sigmoid(x)*(1.0-sigmoid(x)));
}


int main(){
    FILE *fp;
    int ip[226];
    double hiddenlayer[hcount];
    double hinj[hcount];
    double deltainJ[hcount];
    double outputlayer[10];
    double outiny[10];
    double v[226][hcount];
    double vCT[226][hcount];
    double w[hcount][10];
    double deltaK[10];
    double deltaJ[hcount];
    double wCT[hcount][10];
    double max=0;
    int answer=0;
    float a=4.0;
    int targetnumber[10];
    int x=0;
    int num=0;
    const char *number[10]={"0.txt","1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt","9.txt"};

    int i,j,k,s=0;


    srand((unsigned)time(NULL));
 

    for(i=0;i<=225;i++){
        for(s=0;s<=hcount-1;s++){
            v[i][s]=(rand()%2)-0.5;
        }
    }
    for(i=0;i<=hcount-1;i++){
        for(j=0;j<10;j++){
            w[i][j]=(rand()%2)-0.5;
        }
    }
     for(i=0;i<10;i++)
        outputlayer[i]=0;
    
	  
    ip[0]=1;
    hiddenlayer[0]=1.0;

	for(x=0;x<tNum;x++){
		 for(num=0;num<10;num++){
            fp=fopen(number[num],"r");
            for(i=1;i<=225;i++){
                fscanf(fp,"%d",&ip[i]);
            }
        fclose(fp);

        for(i=0;i<10;i++){
            targetnumber[i]=0.0;
        }
        targetnumber[num]=1.0;
        
        while(outputlayer[num]<=0.97){
        
        	

        for(j=1;j<=hcount-1;j++){
            hinj[j]=v[0][j];
            for(i=1;i<=225;i++){
                hinj[j]+=(ip[i]*v[i][j]);
            }
            hiddenlayer[j]=sigmoid(hinj[j]);
            
        }

       
        for(k=0;k<10;k++){
            outiny[k]=w[0][k];
            for(j=1;j<=hcount-1;j++){
                outiny[k]+=(hiddenlayer[j]*w[j][k]);
            }
            outputlayer[k]=sigmoid(outiny[k]);
         
        }
        



        for(k=0;k<10;k++){
            deltaK[k]=(targetnumber[k]-outputlayer[k])*dersigmoid(outiny[k]);
            wCT[0][k]=a*deltaK[k];
            for(j=1;j<=hcount-1;j++)
            	wCT[j][k]=a*deltaK[k]*hiddenlayer[j];
            
        }
        
    
        for(j=1;j<=hcount-1;j++){
            deltainJ[j]=0;
            for(k=0;k<10;k++){
                deltainJ[j]+=(deltaK[k]*w[j][k]);
            }

            deltaJ[j]=deltainJ[j]*dersigmoid(hinj[j]);
        }

        for(j=1;j<=hcount-1;j++){
            for(i=1;i<=225;i++){
                vCT[i][j]=a*deltaJ[j]*ip[i];

            }

        }

        for(j=1;j<=hcount-1;j++){
            for(k=0;k<10;k++){
                w[j][k]+=wCT[j][k];
            }
        }

        for(i=1;i<=225;i++){
            for(j=1;j<=hcount-1;j++){
                v[i][j]+=vCT[i][j];
            }
        }
        
        	


		}
			
	

    }
	}
		
    
    for(num=0;num<10;num++){
    	max=0;
    	answer=0;
    	fp=fopen(number[num],"r");
    	for(i=1;i<=225;i++)
    		fscanf(fp,"%d",&ip[i]);
    	fclose(fp);
    	s=1;
    	 while(s<=hcount-1){
            hinj[s]=v[0][s];
            for(i=1;i<=225;i++){
                hinj[s]+=(ip[i]*v[i][s]);
            }
            hiddenlayer[s]=sigmoid(hinj[s]);
            s++;
        }
         k=0;
        while(k<10){
            outiny[k]=w[0][k];
            for(i=1;i<=hcount-1;i++){
                outiny[k]+=(hiddenlayer[i]*w[i][k]);
            }
            outputlayer[k]=sigmoid(outiny[k]);
            if(outputlayer[k]>max){
            	max=outputlayer[k];
            	answer=k;
			}
		
           
            k++;
        }
        
       
        	for (i = 1; i <= 225; i++) {
			if (ip[i] == 1)
				printf("■ ");
			else
				printf("□ ");
			if (i % 15 == 0) 
                printf("\n");
		}
		printf("result : %d", answer);
		printf("\n\n");
        

    	
	}
    
		
	
    
        printf("count of training:%d\n",x);
         

    return 0;
}

