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
/**%%                    ILUSTRATE THE CONCEPT OF ERROR                    %%**/
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
   int n;                                   //Maximum number of iterations
   int i;                                   //i-th iteration

   fpout=fopen("Results.dat","w");          //File with results

   m=68.1;                                  //Particle mass
   c=15.2;                                  //Friction constant
   vz=0.0;                                  //Initial velocity
   vzn=0.0;                                 //Euler velocity
   idt=0.0;                                 //Initial time
   dt=2;                                    //Time step
   n=10;                                    //Number of iterations

   for(i=0;i<n;i++){                        //Iteration cicle
       vz=(g*m/c)*(1.0 - exp(-c*idt/m));    //Analytical velocity
       if(i == 0){                          //Euler velocity
         vzn=vz;                            //Initial time
       }
       else{
        vzn=vzn + (g - (c/m)*vzn)*dt;
       }
       printf("%f\t%f\t%f\n",idt,vz,vzn);   //Show data in display
       fprintf(fpout,"%f\t%f\t%f\n",idt,vz,vzn); //Save data in file
       idt+=dt;                             //Increase time
   }

   fclose(fpout);                           //Close used files
   return 0;
}



