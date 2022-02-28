/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
/**%%   PROGRAM          FREE FALL WITH FRICTION                           %%**/
/**%%   AUTHOR           ALEXIS TORRES alpixels.io@gmail.com               %%**/
/**%%   LICENCE          GNU LGPL-V3                                       %%**/
/**%%   DATE             FEBREAURY 16, 2022                                %%**/
/**%%   VERSION          BETA                                              %%**/
/**%%                                                                      %%**/
/**%%   OBS              FREE FALL FOR A PARTICLE OF MASS m IN A MEDIUM    %%**/
/**%%                    WITH RESISTENCE PROPORTIONAL TO PARTICLE VELOCITY %%**/
/**%%                    VELOCITY IS DETERMINED WITH AN ANALITICAL EQUATION%%**/
/**%%                    AND THE EULER METHOD. THE PROGRAM IS BUILT TO     %%**/
/**%%                    ILUSTRATE THE CONCEPT OF RELATIVE ERROR           %%**/
/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/


/**%%%%%%%%%%%%%%%%%%%%%%%%%%   PRECOMPILER   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
#include<stdio.h>                           //input/output functions
#include<math.h>                            //mathematical functions

#define g 9.81                              //Global variables

FILE *fpout;                                //Pointer file, file for data

/**%%%%%%%%%%%%%%%%%%%%%%%%%%   MAIN PROGRAM   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%**/
int main(){
   float m;                                 //Particle mass
   float c;                                 //Friction constant
   float vz;                                //Analytical cvlocity at time idt
   float vzn;                               //Euler velocity at time idt
   float idt;                               //Time at iteration i
   float dt;                                //Time step

   float ierr;                              //Relative error at i-th
   float rerr;                              //Mean relative error

   int n;                                   //Maximum number of iterations
   int i;                                   //i-th iteration

   fpout=fopen("Results.dat","w");          //File with results

   m=68.1;                                  //Particle mass
   c=15.2;                                  //Friction constant
   vz=0.0;                                  //Initial velocity
   vzn=0.0;                                 //Euler velocity
   idt=0.0;                                 //Initial time
   dt=0.5;                                  //Time step
   n=40;                                    //Number of iterations
   rerr=0.0;                                //Mean relative error
   ierr=0.0;                                //Relative error

   for(i=0;i<n;i++){                        //Iteration cicle
       vz=(g*m/c)*(1.0 - exp(-c*idt/m));    //Analytical velocity

       if(i == 0){                          //Euler velocity
         vzn=vz;                            //Initial time
       }
       else{
        vzn=vzn + (g - (c/m)*vzn)*dt;
       }

       if(i != 0){                          //Avoid error since vz=0.0
         ierr=(vz - vzn)/vz;                //Relative error at i-th iteration
       }

       rerr+=ierr;                          //Mean relative error
       printf("%f\t%f\t%f\t%f\n",idt,vz,vzn,ierr);
       fprintf(fpout,"%f\t%f\t%f\t%f\n",idt,vz,vzn,ierr);
       idt+=dt;                             //Increase time
   }

   rerr=rerr/(float)n;                      //Mean relative error
   printf("\n\nAverage relative error:%f\n",rerr);

   fclose(fpout);                           //Close used files
   return 0;
}



