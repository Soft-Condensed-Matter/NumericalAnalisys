/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
/**%%   PROGRAM          NUMERICAL STABILITY                               %%**/
/**%%   AUTHOR           ALEXIS TORRES alpixels.io@gmail.com               %%**/
/**%%   LICENCE          GNU LGPL-V3                                       %%**/
/**%%   DATE             FEBREAURY 18, 2022                                %%**/
/**%%   VERSION          BETA                                              %%**/
/**%%                                                                      %%**/
/**%%   OBS              THIS PROGRAM ILLUSTRATE THE NUMERICAL STABILITY   %%**/
/**%%                    OF ALGORITHMS AND CODES AS WELL AS THE USE OF     %%**/
/**%%                    VARIABLES OF DIFFERENT PRECISION                  %%**/
/**%%                    EXAMPLE IS DEVELOPED COMPUTING THE SUM:           %%**/
/**%%                          \sum_{n=1}^{9999999} 1/n^{2}                %%**/
/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/


/**%%%%%%%%%%%%%%%%%%%%%%%%%%   PRECOMPILER   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
#include<stdio.h>                           //input/output functions
#include<math.h>                            //mathematical functions

FILE *fpout;                                //Pointer file, file for data

/**%%%%%%%%%%%%%%%%%%%%%%%%%%   MAIN PROGRAM   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
int main(){
   float fw_sum;                            //Forward sum of each term
   float bw_sum;                            //Backward sum of each term
   float term;                              //Function of interest
   float error;                             //Function of interest
   double dfw_sum;                          //Forward sum of each term double
   double dbw_sum;                          //Backward sum of each term double
   double dterm;                            //Function of interest double
   double derror;                           //Function of interest double
   int n;                                   //Number of iterations
   int i;                                   //i-th iteration

   fpout=fopen("Results.dat","w");          //File with results

   n=10000000;                              //Maximum number of iterations
   fw_sum=0.0;                              //Initialization of forward sum
   bw_sum=0.0;                              //Initialization of backward sum
   dfw_sum=0.0;                             //Initialization of forward sum double
   dbw_sum=0.0;                             //Initialization of backward sum double

   for(i=1;i<n;i++){                        //Forward sum iteration cicle
      term=(float) i;                       //Integer to real conversion
      term=term*term;                       //Denominator of the function of interest
      term=1/term;                          //Function of interest
      fw_sum+=term;                         //Update forward sum value of i-th term

      dterm=(double) i;                     //Integer to real double conversion
      dterm=dterm*dterm;                    //Denominator of the function of interest double
      dterm=1/dterm;                        //Function of interest double
      dfw_sum+=dterm;                       //Update forward sum value of i-th term double
   }

   for(i=n;i>0;i--){                        //Backward sum iteration cicle
      term=(float) i;                       //Integer to real conversion
      term=term*term;                       //Denominator of the function of interest
      term=1/term;                          //Function of interest
      bw_sum+=term;                         //Update backward sum value of i-th term

      dterm=(double) i;                     //Integer to real conversion double
      dterm=dterm*dterm;                    //Denominator of the function of interest double
      dterm=1/dterm;                        //Function of interest double
      dbw_sum+=dterm;                       //Update backward sum value of i-th term double
   }

   error=fw_sum - bw_sum;                   //Absolute error
   derror=dfw_sum - dbw_sum;                //Absolute error double

   printf("The forward sum is: %.12f \t\n",fw_sum);
   printf("The backward sum is: %.12f \t\n",bw_sum);
   printf("Error single precision: %.12f \t\n\n",error);

   printf("The forward sum is: %.12lf \t\n",dfw_sum);
   printf("The backward sum is: %.12lf \t\n",dbw_sum);
   printf("Error double precision: %.12f \t\n\n",derror);

   fprintf(fpout,"The forward sum is: %.12f \t\n",fw_sum);
   fprintf(fpout,"The backward sum is: %.12f \t\n",bw_sum);
   fprintf(fpout,"Error single precision: %.12f \t\n\n",error);

   fprintf(fpout,"The forward sum is: %.12lf \t\n",dfw_sum);
   fprintf(fpout,"The backward sum is: %.12lf \t\n",dbw_sum);
   fprintf(fpout,"Error double precision: %.12f \t\n\n",derror);

   fclose(fpout);                           //Close used files
   return 0;
}



