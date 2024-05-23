//program for bisection method of non linear equation

#include<stdio.h>
#include<math.h>

#define f(x)cos(x) - x * exp(x)

void main(){
    float x0, x1, x2 , f0,f1,f2, e;

    int step = 1;

    up:
    printf("\nEnter two initial guesses:\n");
    scanf("%f%f",&x0,&x1);
    printf("Enter tolerable error:\n");
    scanf("%f",&e);
    f0=f(x0);
    f1=f(x1);

    if(f0 * f1>0.0)
    {
        printf("Incorrect Initial Guesses,\n");
        goto up;
    }
    do{
        x2=(x0+x1)/2;
        f2=f(x2);
        
        if(f0*f2<0){
            x1=x2;
            f1=f2;

        }
        else{
            x0=x2;
            f0=f2;

        }
         printf("%d\t%0.4f\t%0.4f\t%0.4f\t%0.4f\n",step,x0,f0,x1,f1);

        step= step + 1;

    }while (fabs(x1-x0)>e);

    printf("\n Root is:%0.4f\n",x1);
    

}