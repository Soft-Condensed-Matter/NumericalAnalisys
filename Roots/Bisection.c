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

#define Nx 1000000                          //Maximum number of iterations
#define Tol 0.0000001                         //Numerical tolerance

//FILE *fpout;                                //Pointer file, file for data

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

   printf("\n\n Bisection method for\n");
   printf("f(x)=2x^3 - x^2 + x - 1 \n\n");
   printf("Please provide the limit value a\n");
   scanf("%f",&a);
   printf("Please provide the limit value b\n");
   scanf("%f",&b);
   printf("\n\nThe search interval is: [%f,%f]\n\n",a,b);
   printf("Iter\ta_n\t\tb_n\t\tp\t\tf(p)\n");
   printf("---------------------------------------------------------------\n");

   FA=2.0*pow(a,3) - pow(a,2) + a - 1.0;

   for(i=1;i<=Nx;i++){
      p=a + (b-a)*0.5;
      FP=2.0*pow(p,3) - pow(p,2) + p - 1.0;

      printf("%d\t%lf\t%lf\t%lf\t%lf\n",i,a,b,p,FP);

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
   return 0;
}



