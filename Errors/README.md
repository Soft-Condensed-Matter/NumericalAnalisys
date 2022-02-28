Errors and where to find it 
=======


# Numerical error #

_Available methods_:

* `Free fall`:
   This program computes the velocity in a free fall scenario with friction proportional
   to the velocity. Results are computed with the analytical result of the Newton law and
   with the aproximation through the Euler method to respective motion equation.

   ![Expected results](https://github.com/Soft-Condensed-Matter/NumericalAnalisys/blob/main/Errors/FreeFall.png)


* `RelativeError.c`:
   This program computes the relative error between the numerical and analytical solutions
   of the free fall problem at each iteration and also the mean relative error. Results are 
   saved in the Results.dat file for their posterior analysis 


* `Stability.c`:
   The numerical estability or inestability of a code is ilustrated through the Basilea 
   problem. Furthermore the errors due to the numerical representation, single or double 
   presicion are also determined.
