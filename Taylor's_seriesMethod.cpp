//1.	 C program for Taylor Series Method
#include<stdio.h>
void sinx(float,int,int);
void cosx(float,int,int);
void epowerx(int,int);
int main(){
    float x; int y,n;
    printf("enter limit: ");
    scanf("%d",&n);
    printf("enter the value in degree: ");
    scanf("%f",&x);
    y=x;
    x=(3.14/180)*x;
    sinx(x,n,y);
    cosx(x,n,y);
    epowerx(y,n);
	return 0;}
void sinx(float x,int n,int y){
    float term=x,sum=x;
    int i;
    for(i=1;i<=n;i++)    {
        term=((-term)*(x*x))/((2*i)*(2*i+1));
        sum=sum+term;    }
    printf("sin %d=%f\n",y,sum);}
void cosx(float x,int n,int y){
    float term=x,sum=1;    int i;
    for(i=1;i<=n;i++)    {
        term=((-term)*(x*x))/((2*i)*(2*i-1));
        sum=sum+term;    }
    printf("cos %d=%f\n",y,sum);}
void epowerx(int y,int n){
    int i;    float term=1,sum=1;
    for(i=1;i<=n;i++)    {
        term=((term)*y)/i;
        sum=sum+term;    }
    printf("e^%d=%.0f\n",y,sum);
}

