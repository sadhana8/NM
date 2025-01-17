#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
 float x[20], y[20][20], xp, h, sum=0.0, term, first_derivative;
 int i,j, n, index, flag = 0, sign=1;

 /* Reading number of data */
 printf("Enter number of data: ");
 scanf("%d", &n);

 /* Reading actual data of x and y */
 printf("Enter data:\n");
 for(i = 0; i < n ; i++)
 {
  printf("x[%d] = ", i);
  scanf("%f", &x[i]);
  printf("y[%d] = ", i);
  scanf("%f", &y[i][0]);
 }

 /* Reading calculation point */
 printf("Enter at what value of x you want to calculate derivative: ");
 scanf("%f", &xp);

 /* Checking whether given point (xp) is
 a valid point in x data or not */
 for(i=0;i< n;i++)
 {
     if (fabs(xp - x[i])< 0.0001)
     {
        /* index of calculation point */
        index = i;
        flag = 1;
        break;
     }
 }

 /* if flag is still 0 then given point (xp)
 is not a valid point (not in list of x data)
 for this calculation */
 if (flag==0)
 {
     printf("Invalid calculation point. Program exiting...");
     exit(0);
 }

 for(i = 1; i < n; i++)
 {
  for(j = 0; j < n-i; j++)
  {
      y[j][i] = y[j+1][i-1] - y[j][i-1];
  }
 }

 h = x[1] - x[0];


 for(i=1; i< n-index; i++)
 {
     term = pow(y[index][i], i)/i;
     sum = sum + sign*term;
     sign = -sign;
 }


 first_derivative = sum/h;


 printf("First derivative at x = %0.2f is %0.2f", xp, first_derivative);

 return 0;
}
