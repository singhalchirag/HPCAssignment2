#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "util.h"
#include <omp.h>

int main ()
{
        timestamp_type time1, time2;
        get_timestamp(&time1);
	printf("abc");
        gauss(1000);
        get_timestamp(&time2);
        double elapsed = timestamp_diff_in_seconds(time1,time2);
        printf("Time elapsed is %f seconds.\n", elapsed);
        return 0;
}


void jacobi(int Nvalue){

	printf("0");
	int a,b;
	double **prevUValue = (double **)malloc((Nvalue+2) * sizeof(double *));
	for (a=0; a<(Nvalue+2); a++)
		prevUValue[a] = (double *)malloc((Nvalue+2) * sizeof(double));
	
	printf("1");
	
	int k,i,j,bp;
	double hvalue,tempValue;
	double **currentUValue = (double **)malloc((Nvalue+2) * sizeof(double *));
        for (b=0; b<(Nvalue+2); b++)
                currentUValue[b] = (double *)malloc((Nvalue+2) * sizeof(double));
	
	for(i= 0;i<= Nvalue+1; i++){

                        for(j= 0;j<= Nvalue+1; j++){
				if ((i == 0) || (j == 0) || (i == Nvalue+1) || (j == Nvalue+1)){
                                prevUValue[i][j] = 0;}
				else{
				prevUValue[i][j] = .25*(pow((1/(Nvalue + 1)),2));
				}
			
                        }
                }

	
	
	for(k= 0;k< 1000;k++){

		for(i= 1;i<= Nvalue; i++){
			
		for(j= 1;j<= Nvalue; j++){			
		
					tempValue= prevUValue[i-1][j]+prevUValue[i][j-1]+prevUValue[i+1][j]+prevUValue[i][j+1];
					if(k==0){tempValue=0;}
					
					currentUValue[i][j] = .25*(tempValue+pow((1/(Nvalue + 1)),2));	
			

		}
		}
					
		for(i= 0;i<= Nvalue+1; i++){

                	for(j= 0;j<= Nvalue+1; j++){

				prevUValue[i][j] = currentUValue[i][j]; 
		
			}
		}
	}
	
}

void gauseParallel(int Nvalue){

	printf("0");
	int a,b;
	double **prevUValue = (double **)malloc((Nvalue+2) * sizeof(double *));
	for (a=0; a<(Nvalue+2); a++)
		prevUValue[a] = (double *)malloc((Nvalue+2) * sizeof(double));
	
	printf("1");
	
	int k,i,j,bp;
	double hvalue,tempValue;
	double **currentUValue = (double **)malloc((Nvalue+2) * sizeof(double *));
        for (b=0; b<(Nvalue+2); b++)
                currentUValue[b] = (double *)malloc((Nvalue+2) * sizeof(double));
	
	for(i= 0;i<= Nvalue+1; i++){

                        for(j= 0;j<= Nvalue+1; j++){
				if ((i == 0) || (j == 0) || (i == Nvalue+1) || (j == Nvalue+1)){
                                prevUValue[i][j] = 0;}
				else{
				prevUValue[i][j] = .25*(pow((1/(Nvalue + 1)),2));
				}
			
                        }
                }
	
	
	for(k= 0;k< 1000;k++){

		for(i= 1;i<= Nvalue; i++){

		// calculate red ones first
		
		#pragma omp parallel for
		for (j =1;j<= Nvalue;j++){
			// even positions of red starting from zero		
			if(i==0 || i%2 ==0){
				if(j%2 == 0 || j==0){
				//boundry points
				tempValue= prevUValue[i-1][j]+prevUValue[i][j-1]+prevUValue[i+1][j]+prevUValue[i][j+1];
					if(k==0){tempValue=0;}
					
					currentUValue[i][j] = .25*(tempValue+pow((1/(Nvalue + 1)),2));			
				}

			}	
			if(i==1 || i%2 != 0){

				if(j==1 || j%2 != 0){
					
					tempValue= prevUValue[i-1][j]+prevUValue[i][j-1]+prevUValue[i+1][j]+prevUValue[i][j+1];
					if(k==0){tempValue=0;}
					
					currentUValue[i][j] = .25*(tempValue+pow((1/(Nvalue + 1)),2));
				}			
			
			}		
		}
		// black enters
		#pragma omp parallel for
		for (j =1;j<= Nvalue;j++){
			// even positions of black starting from zero		
			if(i==0 || i%2 ==0){
				if(j==1 || j%2 != 0){

				
					tempValue= currentUValue[i-1][j]+currentUValue[i][j-1]+currentUValue[i+1][j]+currentUValue[i][j+1];
					if(k==0){tempValue=0;}
					
					currentUValue[i][j] = .25*(tempValue+pow((1/(Nvalue + 1)),2));
				}

			}	
			if(i==1 || i%2 != 0){

				if(j%2 == 0 || j==0){
					
					tempValue= currentUValue[i-1][j]+currentUValue[i][j-1]+currentUValue[i+1][j]+currentUValue[i][j+1];
					if(k==0){tempValue=0;}
					
					currentUValue[i][j] = .25*(tempValue+pow((1/(Nvalue + 1)),2));				

				}			
			
			}		
		}
			
		
	}
		
		#pragma omp parallel for			
		for(i= 0;i<= Nvalue+1; i++){

                	for(j= 0;j<= Nvalue+1; j++){

				prevUValue[i][j] = currentUValue[i][j]; 
		
			}
		}
	}
	
}

void jacobiparallel(int Nvalue){

	printf("0");
	int a,b;
	double **prevUValue = (double **)malloc((Nvalue+2) * sizeof(double *));
	for (a=0; a<(Nvalue+2); a++)
		prevUValue[a] = (double *)malloc((Nvalue+2) * sizeof(double));
	
	printf("1");
	
	int k,i,j,bp;
	double hvalue,tempValue;
	double **currentUValue = (double **)malloc((Nvalue+2) * sizeof(double *));
        for (b=0; b<(Nvalue+2); b++)
                currentUValue[b] = (double *)malloc((Nvalue+2) * sizeof(double));
	
	for(i= 0;i<= Nvalue+1; i++){

                        for(j= 0;j<= Nvalue+1; j++){
				if ((i == 0) || (j == 0) || (i == Nvalue+1) || (j == Nvalue+1)){
                                prevUValue[i][j] = 0;}
				else{
				prevUValue[i][j] = .25*(pow((1/(Nvalue + 1)),2));
				}
			
                        }
                }

	
	
	for(k= 0;k< 1000;k++){

		for(i= 1;i<= Nvalue; i++){
		#pragma omp parallel for	
		for(j= 1;j<= Nvalue; j++){			
		int my_threadnum = omp_get_thread_num();
    		int numthreads = omp_get_num_threads();	
		//printf("Hello, I'm thread %d out of %d\n", my_threadnum, numthreads);
				
					tempValue= prevUValue[i-1][j]+prevUValue[i][j-1]+prevUValue[i+1][j]+prevUValue[i][j+1];
					if(k==0){tempValue=0;}
					
					currentUValue[i][j] = .25*(tempValue+pow((1/(Nvalue + 1)),2));	
			

		}
		}
		#pragma omp parallel for			
		for(i= 0;i<= Nvalue+1; i++){

                	for(j= 0;j<= Nvalue+1; j++){

				prevUValue[i][j] = currentUValue[i][j]; 
		
			}
		}
	}
	
}


void gauss(int Nvalue){

	printf("0");
	int a,b;
	double **prevUValue = (double **)malloc((Nvalue+2) * sizeof(double *));
	for (a=0; a<(Nvalue+2); a++)
		prevUValue[a] = (double *)malloc((Nvalue+2) * sizeof(double));
	
	printf("1");
	
	int k,i,j,bp;
	double hvalue,tempValue;
	double **currentUValue = (double **)malloc((Nvalue+2) * sizeof(double *));
        for (b=0; b<(Nvalue+2); b++)
                currentUValue[b] = (double *)malloc((Nvalue+2) * sizeof(double));
	
	for(i= 0;i<= Nvalue+1; i++){

                        for(j= 0;j<= Nvalue+1; j++){
				if ((i == 0) || (j == 0) || (i == Nvalue+1) || (j == Nvalue+1)){
                                prevUValue[i][j] = 0;}
				else{
				prevUValue[i][j] = .25*(pow((1/(Nvalue + 1)),2));
				}
			
                        }
                }

	
	
	for(k= 0;k< 1000;k++){

		for(i= 1;i<= Nvalue; i++){
			
		for(j= 1;j<= Nvalue; j++){			
		
					tempValue= currentUValue[i-1][j]+currentUValue[i][j-1]+prevUValue[i+1][j]+prevUValue[i][j+1];
					if(k==0){tempValue=0;}
					
					currentUValue[i][j] = .25*(tempValue+pow((1/(Nvalue + 1)),2));	
			

		}
		}
					
		for(i= 0;i<= Nvalue+1; i++){

                	for(j= 0;j<= Nvalue+1; j++){

				prevUValue[i][j] = currentUValue[i][j]; 
		
			}
		}
	}
	
}
