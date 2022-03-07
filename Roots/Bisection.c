/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
/**%%   PROGRAM          BISECTION METHOD                                  %%**/
/**%%   AUTHOR           ALEXIS TORRES alpixels.io@gmail.com               %%**/
/**%%   LICENCE          GNU LGPL-V3                                       %%**/
/**%%   DATE             FEBREAURY 28, 2022                                %%**/
/**%%   VERSION          BETA                                              %%**/
/**%%                                                                      %%**/
/**%%   OBS              BASED ON MEAN VALUE THEOREM THE PROGRAM DETERMINES%%**/
/**%%                    ONE REAL ROOT OF A FUNCTION DEFINED IN A CLOSED   %%**/
/**%%                    INTERVAL [a,b] WHERE THE FUNCTION SHOWS DIFFERENT %%**/
/**%%                    SING AT f(a) AND f(b). THE MIDDLE POINT IS DEFINE %%**/
/**%%                    IN ORDER TO AVOID ISSUES AT SIMETRICAL INTERVALS  %%**/
/**%%                                                                      %%**/
/**%%                    THIS PROGRAMS SOLVE THE FUNCTION                  %%**/
/**%%                          f(x)=2x^3 - x^2 + x - 1                     %%**/
/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/


/**%%%%%%%%%%%%%%%%%%%%%%%%%%   PRECOMPILER   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
#include<stdio.h>                           //input/output functions
#include<math.h>                            //mathematical functions

#define f(x) 2*pow(x,3) - pow(x,2) + x - 1  //Function to be solved
#define Nx 1000000                          //Maximum number of iterations
#define Tol 0.00001                      //Numerical tolerance

FILE *fpout;                                //Pointer file, file for data

/**%%%%%%%%%%%%%%%%%%%%%%%%%%   MAIN PROGRAM   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
int main(){
   float FA;                                //Function at a
   float FB;                                //Function at b
   float FP;                                //Function at p middle point
   float a;                                 //Interval initial limit
   float b;                                 //Interval final limit
   float p;                                 //Middle point in interval
   float test;                              //Test the sign change
   int i;                                   //i-th iteration

   fpout=fopen("Results.dat","w");          //File with iteration data

   printf("\n\n Bisection method for\n");
   printf("f(x)=2x^3 - x^2 + x - 1 \n\n");
   printf("Please provide the limit value a\n");
   scanf("%f",&a);
   printf("Please provide the limit value b\n");
   scanf("%f",&b);
   printf("\n\nThe search interval is: [%f,%f]\n\n",a,b);
   printf("Iter\ta_n\t\tb_n\t\tp\t\tf(p)\n");
   printf("---------------------------------------------------------------\n");

   FA=f(a);

   for(i=1;i<=Nx;i++){
      p=a + (b-a)*0.5;
      FP=f(p);

      printf("%d\t%lf\t%lf\t%lf\t%lf\n",i,a,b,p,FP);
      fprintf(fpout,"%d\t%lf\t%lf\t%lf\t%lf\n",i,a,b,p,FP);

      if((FP == 0) || (0.5*(b-a) < Tol)){
        printf("\n\nThe root is: %f\n",p);
        goto exit;
      }

      test=FA*FP;
      if(test > 0){
         a=p;
         FA=FP;
      }
      else{
         b=p;
      }
   }

   exit:
   fclose(fpout);
   return 0;
}



