//program for regula-falsi iteration method in non linear method

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) x*log10(x)-1.2
int main(){
    float x0,x1,x2,f0,f1,f2,e;
    int step=1;
    up:
    printf("\n Enter two initial guesses:\n");
    scanf("%f%f",&x0,&x1);
    printf("enter tolerable error: \n");
    scanf("%f",&e);

    f0=f(x0);
    f1=f(x1);
    if(f0*f1>0.0){
        printf("Incorrect initial guesses \n");
        goto up;

    }
    printf("\n step\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do{
        x2=x0-(x0-x1)*f0/(f0-f1);
        f2=f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,x1,x2,f2);
        if(f0*f2<0){
            x1=x2;
            f1=f2;

        }
        else{
            x0=x2;
            f0=f2;

        }
          step=step+1;
    }while(fabs(f2)>e);
    printf("\n Root is:%f",x2);
    getch();
    return 0;   

}