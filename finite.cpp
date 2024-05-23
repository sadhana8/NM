#include <stdio.h>
int main(){
int i,j,k,m,n,x,y;
float a[20][20],l,r,t,b;
FILE *fp;
fp=fopen("c:\\laplace.dat","w"); 
printf("\t_______________________________________________________________\n");
printf("\tProgram to solve Laplace's equation by finite difference method\n");
printf("\t_______________________________________________________________\n");
printf("\tEnter boundary conditions\n");
printf("\tValue on left side: ");
scanf("%f",&l);
printf("\tValue on right side: ");
scanf("%f",&r);
printf("\tValue on top side: ");
scanf("%f",&t);
printf("\tValue on bottom side: ");
scanf("%f",&b);
printf("\tEnter length in x direction: ");
scanf("%d",&x);
printf("\tEnter number of steps in x direction: ");
scanf("%d",&m);
printf("\tEnter length in y direction: ");
scanf("%d",&y);
printf("\tEnter number of steps in y direction: ");
scanf("%d",&n);
m++;
n++; 
            for(i=1;i<=m;i++)  
            {
              a[i][1]=b;
              a[i][n]=t;
            }
            for(i=1;i<=n;i++)
            {
              a[1][i]=l;
              a[m][i]=r;
            }                         
for(i=2;i<m;i++)
for(j=2;j<n;j++)
a[i][j]=t; //initialization of interior grid points 
for(k=0;k<100;k++)
  {
               for(i=2;i<m;i++)
            {
               for(j=2;j<n;j++)
               {
                a[i][j]=(a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1])/4;
               }
            }
   }                     //calculation by Gauss-Seidel Method
            for(i=1;i<=m;i++)
            {
               for(j=1;j<=n;j++)
               fprintf(fp,"%.2f\t",a[i][j]);
            fprintf(fp,"\n");
            }
  fclose(fp);
  printf("\nData stored\nPress any key to exit...");
             
}
